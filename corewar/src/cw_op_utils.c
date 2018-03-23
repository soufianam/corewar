/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_op_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:31:29 by tdeborde          #+#    #+#             */
/*   Updated: 2018/03/23 16:34:31 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champion	*cw_find_player(t_setting setting, int index)
{
	int	i;

	i = setting.nbr_champion;
	while (i)
	{
		if (setting.champion_tab[i].id == index)
			return (&(setting.champion_tab[i]));
		i--;
	}
	return (NULL);
}
