/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_op_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:05:10 by tdeborde          #+#    #+#             */
/*   Updated: 2018/04/20 14:48:35 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	*ft_memcpy_circle(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((char*)dst + i) = *((char*)src + i);
		i = (i + 1) % MEM_SIZE;
	}
	return (dst);
}

void	cw_rev_get(unsigned char *registries, int nb)
{
	int		i;

	i = 4;
	while (--i >= 0)
	{
		registries[i] = (unsigned char)nb;
		nb = nb >> 8;
	}
}

int			cw_read_ocp(t_vm *vm, t_process *process, int *param,
		unsigned char ocp_trunc)
{
	if ((ocp_trunc & 128) && (ocp_trunc & 64))
	{
		*param = cw_get_2(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
		process->pc = (process->pc + 2) % MEM_SIZE;
		*param = (short)*param;
		return (2);
	}
	else if ((ocp_trunc & 128))
	{
		*param = cw_get_4(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
		process->pc = (process->pc + 4) % MEM_SIZE;
		return (4);
	}
	else
	{
		*param = cw_get_1(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
		process->pc = (process->pc + 1) % MEM_SIZE;
		if (*param && !cw_check_reg(*param))
			return (0);
		return (1);
	}
}

int			cw_read_ocp_short(t_vm *vm, t_process *process, int *param,
		unsigned char ocp_trunc)
{
	if (ocp_trunc & 128)
	{
		*param = cw_get_2(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
		process->pc = (process->pc + 2) % MEM_SIZE;
		*param = (short)*param;
		if (ocp_trunc & 64)
			return (2);
		return (4);
	}
	else
	{
		*param = cw_get_1(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
		process->pc = (process->pc + 1) % MEM_SIZE;
		if (*param && !cw_check_reg(*param))
			return (0);
		return (1);
	}
}
