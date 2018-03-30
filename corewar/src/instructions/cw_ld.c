/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:12:39 by tdeborde          #+#    #+#             */
/*   Updated: 2018/03/30 16:43:24 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_ld_param(t_vm *vm, t_process *process, int param[2], int ret[2])
{
	int				i;
	unsigned char	ocp;

	i = -1;
	ocp = vm->vm[(process->pc + process->entrypoint) % MEM_SIZE];
	while (++i < 2)
	{
		if (!(ret[i] = cw_read_ocp(vm, process, &param[i], ocp)))
			return (0);
		ocp = ocp << 2;
	}
	return (1);
}

int		cw_ld(t_vm *vm, t_process *process)
{
	int				param[2];
	int				ret[2];

	process->pc = (process->pc + 1) % MEM_SIZE;
	if (!(cw_ld_param(vm, process, param, ret)))
		return (0);
	cw_rev_get(process->registries[param[1]], param[0]);
	process->carry = !param[0] ? 1 : 0;
	process->next_cycle += 5;
	process->pc = (process->pc + 1) % MEM_SIZE;
	return (1);
}
