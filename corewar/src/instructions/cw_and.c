/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:08:22 by tdeborde          #+#    #+#             */
/*   Updated: 2018/03/27 19:58:25 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			cw_get_param_longdir(t_vm *vm, t_process *process, int *param,
		unsigned char ocp_trunc)
{
	if (ocp_trunc & 4 == 4)
	{
		*param = cw_get_1(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
		if (!cw_check_reg(param))
			return (0);
		*param = process->registries[param];
		process->pc = (process->pc + 2) % MEM_SIZE;
		return (1);
	}
	else if (ocp_trunc & 8 == 8)
	{
		*param = cw_get_4(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
		process->pc = (process->pc + 5) % MEM_SIZE;
		return (4);
	}
	else
	{
		*param = cw_get_2(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
		process->pc = (process->pc + 3) % MEM_SIZE;
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
	ret = 0;
	ocp = vm->vm[(++(process->pc) + process->entrypoint) % MEM_SIZE];
	while (++i < 2)
	{
		if (!(tmp = cw_get_param_longdir(vm, process, &param[i], ocp)
			return (0);
		ocp = ocp >> 2;
		ret += tmp;
	}
	param[i] = cw_get_1(&(vm->vm[((process->pc)++ + process->entrypoint) % MEM_SIZE]))
	if (!cw_check_reg(param[i]))
		return (0);
	process->registries[param[i]] = param[0] & param[1];
	process->carry = !(process->registries[param[i]]) ? 1 : 0;
	process->next_cycle += 6;
	return (1);
}
