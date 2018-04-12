/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_create_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:40:32 by tdeborde          #+#    #+#             */
/*   Updated: 2018/04/10 14:58:23 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_process	*cw_init_process(t_champion champion, int start_pos)
{
	int			i;
	int			id;
	t_process	*process;

	if (!(process = malloc(sizeof(t_process))))
		cw_error(ERR_MALLOC);
	id = champion.id;
	i = REG_NUMBER * REG_SIZE;
	while (i > 4)
	{
		process->registries[i/4][i%4] = 0;
		i--;
	}
	while (--i > -1)
	{
		process->registries[0][i] = (char)id;
		id = id >> 8;
	}
	process->entrypoint = start_pos;
	process->pc = 0;
	process->carry = 0;
	process->next_cycle = 0;
	process->live = 0;
	return (process);
}

void		cw_add_process(t_vm *vm, t_champion champion, int start_pos)
{
	t_list		*new_process;
	t_process	*process;

	process = cw_init_process(champion, start_pos);
	if (!(new_process = ft_lstnew(process, sizeof(t_process*))))
		cw_error(ERR_MALLOC);
	ft_lstaddend(&(vm->process), new_process);
}

void		cw_create_process(t_vm *vm)
{
	t_setting	setting;
	t_champion	champion;
	int			i;
	int			start_pos;

	i = -1;
	start_pos = 0;
	setting = vm->setting;
	while (++i < setting.nbr_champion)
	{
		champion = setting.champion_tab[i];
		ft_memcpy(vm->vm + start_pos, champion.bin, champion.size_prog);
		cw_add_process(vm, champion, start_pos);
		start_pos += (MEM_SIZE / setting.nbr_champion);
	}
}
