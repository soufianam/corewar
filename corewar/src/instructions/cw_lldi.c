/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 11:48:05 by tdeborde          #+#    #+#             */
/*   Updated: 2018/04/20 11:48:10 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_lldi_param(t_vm *vm, t_process *process, int param[2], int ret[2])
{
	int				i;
	int				check;
	int				offset;
	unsigned char	ocp;

	i = -1;
	check = 1;
	offset = 1;
	ocp = vm->vm[(process->pc + process->entrypoint) % MEM_SIZE];
	while (++i < 3)
	{
		if (!(ret[i] = cw_read_ocp_short(vm, process, &param[i], ocp)))
		{
			ret[i] += 1;
			check = 0;
		}
		offset += ret[i] == 4 ? 2 : ret[i];
		if (ret[i] == 1 & i < 2)
			param[i] = cw_get_4(process->registries[param[i] - 1]);
		else if (ret[i] == 2)
			param[i] = cw_get_4(&(vm->vm[(process->pc + process->entrypoint
							- offset + ((short)param[i] % IDX_MOD)) % MEM_SIZE]));
		ret[i] = ret[i] == 4 ? 2 : ret[i];
		ocp = ocp << 2;
	}
	return (check ? offset : 0);
}

int		cw_lldi(t_vm *vm, t_process *process)
{
	int				param[3];
	int				ret[3];
	int				offset;

	process->pc = (process->pc + 1) % MEM_SIZE;
	if ((offset = cw_lldi_param(vm, process, param, ret)))
	{
		ft_memcpy(process->registries[param[2] - 1], &(vm->vm[(process->pc
			+ process->entrypoint + param[0] + param[1] - offset) % MEM_SIZE]), REG_SIZE);
		process->carry = !param[0] ? 1 : 0;
	}
	process->pc = (process->pc + 1) % MEM_SIZE;
	cw_wait_process(vm, process);
	if (DEBUG)
	{
		ft_printf("--cycle %d--\nlldi: (%d) + (%d) -> r%d\n", vm->cycle, param[0], param[1], param[2]);
	}
	return (1);
}
