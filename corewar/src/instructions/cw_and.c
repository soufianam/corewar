/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:08:22 by tdeborde          #+#    #+#             */
/*   Updated: 2018/03/28 17:32:10 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			cw_get_param_longdir(t_vm *vm, t_process *process, int *param,
		unsigned char ocp_trunc)
{
	if ((ocp_trunc & 4) == 4)
	{
		*param = cw_get_1(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
		if (*param && !cw_check_reg(*param))
			return (0);
		process->pc = (process->pc + 1) % MEM_SIZE;
		return (1);
	}
	else if ((ocp_trunc & 8) == 8)
	{
		*param = cw_get_4(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
		process->pc = (process->pc + 4) % MEM_SIZE;
		return (4);
	}
	else
	{
		*param = cw_get_2(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
		process->pc = (process->pc + 2) % MEM_SIZE;
		return (2);
	}
}

int			cw_and(t_vm *vm, t_process *process)
{
	int				i;
	int				param[3];
	int				ret;
	unsigned char	ocp;

	i = -1;
	process->pc = (process->pc + 1) % MEM_SIZE;
	ocp = vm->vm[(process->pc + process->entrypoint) % MEM_SIZE];
	while (++i < 3)
	{
		if (!(ret = cw_get_param_longdir(vm, process, &param[i], ocp)))
			return (0);
		else if (ret == 1 && i < 2)
			param[i] = cw_get_4(process->registries[param[i]]);
		ocp = ocp >> 2;
	}
	cw_rev_get(process->registries[param[i - 1]], (param[0] & param[1]));
	process->carry = !(param[0] & param[1]) ? 1 : 0;
	process->next_cycle += 6;
	process->pc = (process->pc + 1) % MEM_SIZE;
	return (1);
}
