/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:21:13 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/23 16:21:48 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_dump_and_quit(t_vm *vm)
{
	int		i;
	char	*res;

	res = 0;
	i = 0;
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

static char	*cw_find_player(t_setting setting, int index)
{
	int	i;

	i = setting.nbr_champion;
	while (i)
	{
		if (setting.champion_tab[i].id == index)
			return (setting.champion_tab[i].name);
		i--;
	}
	cw_error(ERR_UNKNOW);
	return (0);
}

void	cw_game_over(t_vm *vm)
{
	int		index;

	index = vm->loop.last_live.index;
	if (index == -1)
		ft_printf("No procces found living");
	else
		ft_printf("Player %d %s won\n", index, \
			cw_find_player(vm->setting, index));
	exit(0);
}
