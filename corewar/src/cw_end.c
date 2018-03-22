/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:21:13 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/22 13:54:55 by blefeuvr         ###   ########.fr       */
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
		res = ft_strext(res, ft_itoa_base(vm->vm[i], "0123456789abcdef"));
		if (i % 32 == 0)
		{
			ft_putendl(res);
			ft_strdel(&res);
		}
		i++;
	}
	exit(0);
}

void	cw_game_over(t_vm *vm)
{
	ft_printf("Player %d %s won\n", vm->loop.last_live.index, \
			vm->setting.champion_tab[vm->loop.last_live.index]);
	exit(0);
}
