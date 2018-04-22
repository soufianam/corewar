/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:52:37 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/20 13:39:45 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			cw_live(t_vm *vm, t_process *process)
{
	t_champion	*champ;
	int			id;

	process->pc = (process->pc + 1) % MEM_SIZE;
	id = cw_get_4(&(vm->vm[(process->pc + process->entrypoint) % MEM_SIZE]));
	process->pc = (process->pc + 4) % MEM_SIZE;
	if (!(champ = cw_find_player(&(vm->setting), id)))
		ft_printf("Live failed : no player found for id %d\n", id);
	else
	{
		ft_printf("Player %s (%d) has been reported alive.\n", champ->name, id);
		vm->loop.last_live.index = id;
		vm->loop.last_live.cycle = vm->cycle;
	}
	process->live += 1;
	cw_wait_process(vm, process);
	if (DEBUG)
	{
		ft_printf("--cycle %d--\nlive: %d\n", vm->cycle, id);
	}
	return (1);
}
