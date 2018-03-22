/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:21:13 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/22 15:33:36 by blefeuvr         ###   ########.fr       */
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
		res = ft_strext(res, cw_itoa_base(vm->vm[i], "0123456789abcdef"));
		if (i % 32 != 0)
			res = ft_strext(res, " ");
		else
		{
			ft_putendl(res);
			ft_strdel(&res);
		}
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
		if (setting.champion_tab[i].number == index)
			return (setting.champion_tab[i].name);
		i--;
	}
	cw_error(ERR_UNKNOW);
	return (0);
}

void	cw_game_over(t_vm *vm)
{
	ft_printf("Player %d %s won\n", vm->loop.last_live.index, \
		cw_find_player(vm->setting, vm->loop.last_live.index));
	exit(0);
}
