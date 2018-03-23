/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:52:37 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/23 17:08:51 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_get_champ_id(t_vm *vm, t_process *process)
{
	char	*ram;
	int		id;
	int		i;

	i = -1;
	id = 0;
	ram = &(vm->vm[(process->pc + process->entrypoint + 1) % MEM_SIZE]);
	while (++i < 4)
	{
		id += ram[i];
		id = id << 8;
	}
	return (id);
}

void	cw_live(t_vm *vm, t_process *process)
{
	t_champion	*champ;
	int			id;

	id = cw_get_champ_id(vm, process);
	if (!(champ = cw_find_player(&(vm->setting), id)))
		ft_printf("Live failed : no player found for id %d", id);
	else
	{
		ft_printf("Player %S (%d) has been reported alive.\n",
			champ->name, id);
		vm->loop.last_live.index = id;
		vm->loop.last_live.cycle = vm->cycle;
		process->pc = (process->pc + 5) % MEM_SIZE;
		process->next_cycle += 10;
	}
}
