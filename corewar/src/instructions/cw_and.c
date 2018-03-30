/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:08:22 by tdeborde          #+#    #+#             */
/*   Updated: 2018/03/30 16:46:43 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_and_param(t_vm *vm, t_process *process, int param[3], int ret[3])
{
	int				i;
	unsigned char	ocp;

	i = -1;
	ocp = vm->vm[(process->pc + process->entrypoint) % MEM_SIZE];
	while (++i < 3)
	{
		if (!(ret[i] = cw_read_ocp(vm, process, &param[i], ocp)))
			return (0);
		else if (ret[i] == 1 && i > 0)
			param[i] = cw_get_4(process->registries[param[i]]);
		ocp = ocp << 2;
	}
	return (1);
}
int			cw_and(t_vm *vm, t_process *process)
{
	int				param[3];
	int				ret[3];

	process->pc = (process->pc + 1) % MEM_SIZE;
	if (!(cw_and_param(vm, process, param, ret)))
		return (0);
	cw_rev_get(process->registries[param[0]], (param[1] & param[2]));
	process->carry = !(param[1] & param[2]) ? 1 : 0;
	process->next_cycle += 6;
	process->pc = (process->pc + 1) % MEM_SIZE;
	return (1);
}
