/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:12:39 by tdeborde          #+#    #+#             */
/*   Updated: 2018/03/23 18:30:09 by tdeborde         ###   ########.fr       */
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

void	cw_ld(t_vm *vm, t_process *process)
{
	unsigned char	ocp;
	int				len;
	int				param1;
	int				param2;

	process->pc = (process->pc + 1) % MEM_SIZE;
	if ((ocp = vm->vm[(process->pc + process->entrypoint) % MEM_SIZE]) == 208)
	{
		param1 = cw_get_2(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
		param2 = cw_get_1(&(vm->vm[(process->pc + process->entrypoint + 3) % MEM_SIZE]));
		len = 2;
	}
	else
	{
		param1 = cw_get_4(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
		param2 = cw_get_1(&(vm->vm[(process->pc + process->entrypoint + 5) % MEM_SIZE]));
		len = 4;
	}
	process->pc = (process->pc + 2 + len) % MEM_SIZE;
	cw_rev_get(process->registries[param2], param1);
	process->carry = !param1 ? 1 : 0;
}
