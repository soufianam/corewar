/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:11:23 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/09 12:47:50 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_dump_and_quit(t_vm *vm)
{
	int		i;
	char	*res;

	res = 0;
	i = 0;
	/**/
	/*debug*/
	/*cycle*/
	ft_printf("Cycle: %d\n", vm->cycle);
	/*players process & registres*/
	while (i < vm->setting.nbr_champion)
	{
		ft_printf("Player %d: %s\n", vm->setting.champion_tab[i].id, vm->setting.champion_tab[i].name);
		i++;
	}
	/**/
	while (i < MEM_SIZE)
	{
		ft_printf("%02hhx", vm->vm[i]);
		if ((i + 1) % 32 != 0)
			ft_putchar(' ');
		else
			ft_putchar('\n');
		i++;
	}
	exit(0);
}

void	cw_game_over(t_vm *vm)
{
	t_champion	*champ;
	int		index;

	index = vm->loop.last_live.index;
	champ = cw_find_player(&(vm->setting), index);
	if (index == -1 || !champ)
		ft_printf("No process found living for a champion\n");
	else
		ft_printf("Player %d %s won\n", index, champ->name);
	exit(0);
}
