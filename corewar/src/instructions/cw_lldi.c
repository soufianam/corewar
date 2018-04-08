/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:12:39 by tdeborde          #+#    #+#             */
/*   Updated: 2018/03/30 18:17:21 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_lldi_param(t_vm *vm, t_process *process, int param[2], int ret[2])
{
	int				i;
	unsigned char	ocp;

	i = -1;
	ocp = vm->vm[(process->pc + process->entrypoint) % MEM_SIZE];
	while (++i < 3)
	{
		if (!(ret[i] = cw_read_ocp_nomod(vm, process, &param[i], ocp)))
			return (0);
		else if (ret[i] == 1 & i < 2)
			param[i] = cw_get_4(process->registries[param[i]]);
		ocp = ocp << 2;
	}
	return (1);
}

int		cw_lldi(t_vm *vm, t_process *process)
{
	int				param[3];
	int				ret[3];

	process->pc = (process->pc + 1) % MEM_SIZE;
	if (!(cw_lldi_param(vm, process, param, ret)))
		return (0);
	ft_memcpy(process->registries[param[2]], &(vm->vm[(process->pc
		+ process->entrypoint + param[0] + param[1] - ret[0] - 4) % MEM_SIZE]), REG_SIZE);
	process->carry = !param[0] ? 1 : 0;
	process->next_cycle += 25;
	process->pc = (process->pc + 1) % MEM_SIZE;
	return (1);
}