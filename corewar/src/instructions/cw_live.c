/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:52:37 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/24 16:59:38 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			cw_live(t_vm *vm, t_process *process)
{
	t_champion	*champ;
	int			id;

	process->pc = (process->pc + 1) % MEM_SIZE;
	id = cw_get_4(&(vm->vm[(process->pc + process->entrypoint) % MEM_SIZE]));
	if (!(champ = cw_find_player(&(vm->setting), id)))
	{
		ft_printf("Live failed : no player found for id %d", id);
		return (0);
	}
	ft_printf("Player %S (%d) has been reported alive.\n",
		champ->name, id);
	vm->loop.last_live.index = id;
	vm->loop.last_live.cycle = vm->cycle;
	process->pc = (process->pc + 4) % MEM_SIZE;
	process->next_cycle += 10;
	return (1);
}
