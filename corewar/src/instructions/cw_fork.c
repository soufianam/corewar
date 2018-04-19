/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:43:19 by tdeborde          #+#    #+#             */
/*   Updated: 2018/04/19 14:57:11 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_fork(t_vm *vm, t_process *process)
{
	t_list	*new;
	int		param;
	int		old_pc;

	param = cw_get_2(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
	old_pc = process->pc;
	process->pc = (process->pc + 3) % MEM_SIZE;
	if (!(new = ft_lstnew(process, sizeof(t_process))))
		cw_error(ERR_MALLOC);
	((t_process*)new->content)->pc = (short)(old_pc + param) % IDX_MOD;
	((t_process*)new->content)->live = 0;
	((t_process*)new->content)->entrypoint = 0;
	ft_lstpushf(&(vm->process), new);
	cw_wait_process(vm, process);
	cw_wait_process(vm, (t_process*)new->content);
	return (1);
}
