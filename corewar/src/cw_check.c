/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 09:21:32 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/20 13:42:18 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_check_live(t_process *process, void *none)
{
	none = 0;
	if (process->live > 0)
		return (1);
	return (0);
}

void	cw_check_process(t_vm *vm)
{
	t_list		*curr;
	int			live;

	ft_lstdelif(&(vm->process), 0, &cw_check_live);
	curr = vm->process;
	live = 0;
	while (curr)
	{
		live += ((t_process*)curr->content)->live;
		((t_process*)curr->content)->live = 0;
		curr = curr->next;
	}
	ft_printf("%d\n", live);
	if (live == 0)
		cw_game_over(vm);
	if (live > NBR_LIVE)
	{
		vm->loop.cycle_to_die -= CYCLE_DELTA;
		vm->loop.next_max_check += vm->loop.cycle_to_die * MAX_CHECKS;
	}
}
