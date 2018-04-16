/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_op_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 20:11:08 by tdeborde          #+#    #+#             */
/*   Updated: 2018/04/16 12:05:25 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			cw_read_ocp_nomod(t_vm *vm, t_process *process, int *param,
		unsigned char ocp_trunc)
{
	if ((ocp_trunc & 128) && (ocp_trunc & 64))
	{
		*param = cw_get_2(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
		process->pc = (process->pc + 2) % MEM_SIZE;
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
