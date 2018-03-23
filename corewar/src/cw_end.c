/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:21:13 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/23 16:33:57 by tdeborde         ###   ########.fr       */
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

void	cw_game_over(t_vm *vm)
{
	t_champion	*champ;

	if (!(champ = cw_find_player(vm->setting, vm->loop.last_live.index)))
		cw_error(ERR_UNKNOW);
	ft_printf("Player %d %s won\n", vm->loop.last_live.index, champ->name);
	exit(0);
}
