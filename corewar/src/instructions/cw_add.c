/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:48:08 by tdeborde          #+#    #+#             */
/*   Updated: 2018/04/18 16:18:42 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_add_param(t_vm *vm, t_process *process, int param[3], int ret[3])
{
	int				i;
	int				check;
	unsigned char	ocp;

	i = -1;
	check = 1;
	ocp = vm->vm[(process->pc + process->entrypoint) % MEM_SIZE];
	while (++i < 3)
	{
		if (!(ret[i] = cw_read_ocp(vm, process, &param[i], ocp)))
		{
			ret[i] += 1;
			check = 0;
		}
		else if (ret[i] == 1 && i < 2)
			param[i] = cw_get_4(process->registries[param[i] - 1]);
		ocp = ocp << 2;
	}
	return (check);
}

int		cw_add(t_vm *vm, t_process *process)
{
	int				param[3];
	int				ret[3];

	process->pc = (process->pc + 1) % MEM_SIZE;
	if ((cw_add_param(vm, process, param, ret)))
	{
		cw_rev_get(process->registries[param[2] - 1], (param[0] + param[1]));
		process->carry = !(param[0] + param[1]) ? 1 : 0;
	}
	process->pc = (process->pc + 1) % MEM_SIZE;
	cw_wait_process(vm, process);
	return (1);
}
