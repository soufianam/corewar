/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:47:42 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/23 17:01:11 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_process_process(t_list *process, t_vm *vm, int cycle)
{
	t_list *curr;

	(void)vm;
	curr = process;
	while (curr)
	{
		if (((t_process*)curr->content)->next_cycle == cycle)
			cw_exec_process(vm, curr->content);
		curr = curr->next;
	}
}

void	cw_exec_process(t_vm *vm, t_process *process)
{
	t_op	op;
	
	op = optab[(int)vm->vm[(process->pc + process->entrypoint) % MEM_SIZE]];
	op.f(vm, process, op);
}
