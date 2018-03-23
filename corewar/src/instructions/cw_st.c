/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:32:07 by tdeborde          #+#    #+#             */
/*   Updated: 2018/03/23 20:19:01 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			cw_get_param(t_vm *vm, t_process *process, int *param1, int *param2)
{
	unsigned char	ocp;

	if ((ocp = vm->vm[(++(process->pc) + process->entrypoint) % MEM_SIZE])
			== 50)
	{
		*param1 = cw_get_1(&(vm->vm[(++(process->pc) + process->entrypoint)
					% MEM_SIZE]));
		*param2 = cw_get_1(&(vm->vm[(++(process->pc) + process->entrypoint)
					% MEM_SIZE]));
		process->pc++;
		return (0);
	}
	*param1 = cw_get_1(&(vm->vm[(++(process->pc) + process->entrypoint)
				% MEM_SIZE]));
	*param2 = cw_get_2(&(vm->vm[(++(process->pc) + process->entrypoint)
				% MEM_SIZE]));
	process->pc += 2;
	return (1);
}

int			cw_st(t_vm *vm, t_process *process)
{
	unsigned char	ocp;
	int				param1;
	int				param2;
	int				ret;

	ret = cw_get_params(vm, process, &param1, &param2);
	process->carry = !param1 ? 1 : 0;
	if (!cw_check_reg(process, param1))
		return (0);
	if (!ret)
	{
		if (!cw_check_reg(process, param2))
			return (0)
		ft_memcpy(process->registries[param2], process->registries[param1],
				REG_SIZE);
	}
	else
		ft_memcpy(&(vm->vm[(process->pc + process->entrypoint + param2 - ret - 4) % MEM_SIZE]),
				process->registries[param1], REG_SIZE);
	process->next_cycle += 5;
	return (1);
}
