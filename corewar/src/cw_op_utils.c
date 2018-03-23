/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_op_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:31:29 by tdeborde          #+#    #+#             */
/*   Updated: 2018/03/23 18:23:26 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champion	*cw_find_player(t_setting *setting, int index)
{
	int	i;

	i = setting->nbr_champion;
	while (i)
	{
		if (setting->champion_tab[i].id == index)
			return (&(setting->champion_tab[i]));
		i--;
	}
	return (NULL);
}

int	cw_get_1(char *vm)
{
	return (vm[0]);
}

int	cw_get_2(char *vm)
{
	return (vm[0] << 8 | vm[1]);
}

int	cw_get_4(char *vm)
{
	return (vm[0] << 24 | vm[1] << 16 | vm[2] << 8 | vm[3]);
}
