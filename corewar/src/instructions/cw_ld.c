/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:12:39 by tdeborde          #+#    #+#             */
/*   Updated: 2018/04/20 11:53:34 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_ld_param(t_vm *vm, t_process *process, int param[2], int ret[2])
{
	int				i;
	int				check;
	int				offset;
	unsigned char	ocp;

	i = -1;
	offset = 1;
	check = 1;
	ocp = vm->vm[(process->pc + process->entrypoint) % MEM_SIZE];
	while (++i < 2)
	{
		if (!(ret[i] = cw_read_ocp(vm, process, &param[i], ocp)))
		{
			ret[i] += 1;
			check = 0;
		}
		offset += ret[i];
		if (ret[i] == 2)
			param[i] = cw_get_4(&(vm->vm[(process->pc + process->entrypoint
							- offset + ((short)param[i] % IDX_MOD)) % MEM_SIZE]));
		ocp = ocp << 2;
	}
	return (check);
}

int		cw_ld(t_vm *vm, t_process *process)
{
	int				param[2];
	int				ret[2];

	process->pc = (process->pc + 1) % MEM_SIZE;
	if ((cw_ld_param(vm, process, param, ret)))
	{
		cw_rev_get(process->registries[param[1] - 1], param[0]);
		process->carry = !param[0] ? 1 : 0;
	}
	process->pc = (process->pc + 1) % MEM_SIZE;
	cw_wait_process(vm, process);
	if (DEBUG)
	{
		ft_printf("--cycle %d--\nld: %d -> %d\n", vm->cycle, param[0], param[1]);
	}
	return (1);
}
