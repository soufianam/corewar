/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:43:19 by tdeborde          #+#    #+#             */
/*   Updated: 2018/04/18 12:14:24 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_lfork(t_vm *vm, t_process *process)
{
	t_list	*new;
	int		param;

	param = cw_get_2(&(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]));
	process->pc = (process->pc + 3) % MEM_SIZE;
	if (!(new = ft_lstnew(process, sizeof(t_process))))
		cw_error(ERR_MALLOC);
	((t_process*)new->content)->pc = param;
	ft_lstaddend(&(vm->process), new);
	return (1);
}
