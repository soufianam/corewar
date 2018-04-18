/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:47:42 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/18 10:50:28 by blefeuvr         ###   ########.fr       */
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
	int		opcode;
	int		i;

	opcode = vm->vm[(process->pc + process->entrypoint) % MEM_SIZE];
	i = 0;
	while (op_tab[i].opcode != opcode)
		i++;
	op = op_tab[i];
	op.f(vm, process);
}

void	cw_wait_process(t_vm *vm, t_process *process)
{
	int		opcode;
	int		i;

	opcode = vm->vm[(process->pc + process->entrypoint) % MEM_SIZE];
	while (opcode < 1 || opcode > 15)
	{
		process->pc += 1;
		opcode = vm->vm[(process->pc + process->entrypoint) % MEM_SIZE];
	}
	i = 0;
	while (op_tab[i].opcode != opcode)
		i++;
	process->next_cycle += op_tab[i].nb_cycle;
}
