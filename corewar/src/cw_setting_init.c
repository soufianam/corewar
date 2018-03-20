/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_setting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:26:21 by cmaxime           #+#    #+#             */
/*   Updated: 2018/03/20 09:23:09 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_init_setting(t_setting *setting)
{
	setting->nbr_cycle = -1;
	setting->nbr_champion = 0;
}

int		cw_init_dump(t_setting *setting, int ac, char **av, int i)
{
	if (i < ac && ft_strcmp(av[i], "-dump") == 0)
	{
		i++;
		if (i < ac && ft_isnum(tab[i]))
		{
			setting->nbr_cycle = (int)ft_atoi_base_max(tab[i], 10);
			i++;
		}
	}
	return (i);
}

int		cw_init_champion(t_setting *setting, int ac, char **av, int i)
{
	if (i < ac && ft_strcmp(tab[i], "-n") == 0)
	{
		i++;
		if (i < ac && cw_strisdig(tab[i])
				&& setting->nbr_champion < MAX_PLAYERS)
		{
			i++;
			// AJOUTER UN CHAMPION
			setting->nbr_champion++;
		}
	}
	return (i);
}

int		cw_load_settings(t_setting *setting, int ac, char **av)
{
	int		i;

	i = 1;
	cw_init_setting(setting);
	if ((i = cw_init_dump(setting, ac, av, i)) % 2 != 1)
		return (0);
	while ((i = cw_init_champion(setting, ac, av, i)) < ac && i != -1);
	return (i);
}
