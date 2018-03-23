/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:12:39 by tdeborde          #+#    #+#             */
/*   Updated: 2018/03/23 20:19:02 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_rev_get(char *registries, int nb)
{
	int		i;

	i = 4;
	while (--i)
	{
		registries[i] = (char)nb;
		nb = nb >> 8;
	}
}

void	cw_get_param(t_vm *vm, t_process *process, int *param1, int *param2)
{
	unsigned char	ocp;

	if ((ocp = vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]) == 208)
	{
		*param1 = cw_get_2(&(vm->vm[(process->pc + process->entrypoint + 2) % MEM_SIZE]));
		*param2 = cw_get_1(&(vm->vm[(process->pc + process->entrypoint + 4) % MEM_SIZE]));
		process->pc = (process->pc + 5) % MEM_SIZE;
	}
	else
	{
		*param1 = cw_get_4(&(vm->vm[(process->pc + process->entrypoint + 2) % MEM_SIZE]));
		*param2 = cw_get_1(&(vm->vm[(process->pc + process->entrypoint + 6) % MEM_SIZE]));
		process->pc = (process->pc + 7) % MEM_SIZE;
	}
}

void	cw_ld(t_vm *vm, t_process *process)
{
	unsigned char	ocp;
	int				param1;
	int				param2;

	cw_get_params(vm, process, &param1, &param2);
	process->carry = !param1 ? 1 : 0;
	if (param2 < 1 || param2 >= REG_NUMBER)
		ft_printf("Ld failed : no registries found for reg_index %d", param2);
	else
	{
		cw_rev_get(process->registries[param2], param1);
		process->next_cycle += 5;
	}
}
