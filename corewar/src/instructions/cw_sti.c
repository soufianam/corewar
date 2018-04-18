/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:08:22 by tdeborde          #+#    #+#             */
/*   Updated: 2018/04/18 12:21:11 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_sti_param(t_vm *vm, t_process *process, int param[3], int ret[3])
{
	int				i;
	int				check;
	unsigned char	ocp;

	i = -1;
	check = 1;
	ocp = vm->vm[(process->pc + process->entrypoint) % MEM_SIZE];
	while (++i < 3)
	{
		if (!(ret[i] = cw_read_ocp_short(vm, process, &param[i], ocp)))
		{
			ret[i] += 1;
			check = 0;
		}
		else if (ret[i] == 1 && i > 0)
			param[i] = cw_get_4(process->registries[param[i] - 1]);
		ocp = ocp << 2;
	}
	return (check);
}

int		cw_sti(t_vm *vm, t_process *process)
{
	int				param[3];
	int				ret[3];

	process->pc = (process->pc + 1) % MEM_SIZE;
	if ((cw_sti_param(vm, process, param, ret)))
	{
		ft_memcpy(&(vm->vm[(process->pc + process->entrypoint + param[1] + param[2]
			- ret[1] - 4) % MEM_SIZE]), process->registries[param[0] - 1], REG_SIZE);
		process->carry = !process->registries[param[0] - 1] ? 1 : 0;
	}
	process->pc = (process->pc + 1) % MEM_SIZE;
	cw_wait_process(vm, process);
	if (DEBUG)
	{
		printf("--cycle %d--\nsti: r%d (%d) -> %d + %d\n", vm->cycle, param[0], cw_get_4(process->registries[param[0] - 1]), param[1], param[2]);
	}
	return (1);
}
