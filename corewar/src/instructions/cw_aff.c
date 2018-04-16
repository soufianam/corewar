/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:10:34 by tdeborde          #+#    #+#             */
/*   Updated: 2018/04/16 12:39:19 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			cw_aff(t_vm *vm, t_process *process)
{
	int	param;

	param = cw_get_2(&(vm->vm[(process->pc + process->entrypoint + 2) % MEM_SIZE]));
	param = param % 256;
	process->pc = (process->pc + 4) % MEM_SIZE;
	ft_printf("%C", (unsigned char)param);
	return (1);
}
