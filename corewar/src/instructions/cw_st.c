/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:32:07 by tdeborde          #+#    #+#             */
/*   Updated: 2018/04/18 12:20:38 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_st_param(t_vm *vm, t_process *process, int param[2], int ret[2])
{
	int				i;
	int				check;
	unsigned char	ocp;

	i = -1;
	check = 1;
	ocp = vm->vm[(process->pc + process->entrypoint) % MEM_SIZE];
	while (++i < 2)
	{
		if (!(ret[i] = cw_read_ocp(vm, process, &param[i], ocp)))
		{
			ret[i] += 1;
			check = 0;
		}
		else if (ret[i] == 1 && i == 0)
			param[i] = cw_get_4(process->registries[param[i] - 1]);
		ocp = ocp << 2;
	}
	return (check);
}

int		cw_st(t_vm *vm, t_process *process)
{
	int				param[2];
	int				ret[2];

	process->pc = (process->pc + 1) % MEM_SIZE;
	if ((cw_st_param(vm, process, param, ret)))
	{
		if (ret[1] == 1)
			ft_memcpy(process->registries[param[1] - 1], process->registries[param[0] - 1],
				REG_SIZE);
		else
			ft_memcpy(&(vm->vm[(process->pc + process->entrypoint + (param[1] % IDX_MOD)
				- ret[1] - 2) % MEM_SIZE]), process->registries[param[0] - 1], REG_SIZE);
		process->carry = !(param[0]) ? 1 : 0;
	}
	process->pc = (process->pc + 1) % MEM_SIZE;
	cw_wait_process(vm, process);
	return (1);
}
