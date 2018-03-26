/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:08:22 by tdeborde          #+#    #+#             */
/*   Updated: 2018/03/26 18:11:54 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			cw_get_param_sti(t_vm *vm, t_process *process, int *param2,
		int *param3)
{
	unsigned char	ocp;

	if (!((ocp = vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE])
			& 32))
	{
		*param2 = cw_get_1(&(vm->vm[(process->pc + process->entrypoint + 3)
					% MEM_SIZE]));
		*param3 = cw_get_2(&(vm->vm[(process->pc + process->entrypoint + 4)
					% MEM_SIZE]));
		process->pc = (process->pc + 6) % MEM_SIZE;
		return (0);
	}
	*param2 = cw_get_2(&(vm->vm[(process->pc + process->entrypoint + 3)
				% MEM_SIZE]));
	*param3 = cw_get_2(&(vm->vm[(process->pc + process->entrypoint + 5)
					% MEM_SIZE]));
	process->pc = (process->pc + 7) % MEM_SIZE;
	return (1);
}

int			cw_sti(t_vm *vm, t_process *process)
{
	int				param1;
	int				param2;
	int				param3;
	int				ret;

	param1 = cw_get_1(&(vm->vm[(process->pc + process->entrypoint + 2)
				% MEM_SIZE]));
	ret = cw_get_param_sti(vm, process, &param2, &param3);
	if (!cw_check_reg(param1))
		return (0);
	process->carry = !process->registries[param1] ? 1 : 0;
	if (!ret)
	{
		if (!cw_check_reg(param2))
			return (0);
		param2 = cw_get_4(process->registries[param2]);
	}
	ft_memcpy(&(vm->vm[(process->pc + process->entrypoint + param2 + param3 - ret
		- 6) % MEM_SIZE]), process->registries[param1], REG_SIZE);
	process->next_cycle += 25;
	return (1);
}
