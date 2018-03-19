/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_setting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:26:21 by cmaxime           #+#    #+#             */
/*   Updated: 2018/03/19 18:34:38 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_init_dump(t_setting *setting, int ac, char **av, int i)
{
	if (i < ac && ft_strcmp(av[i], "-dump") == 0)
	{
		i++;
		if (i < ac && cw_strisdig(tab[i]))
		{
			setting->nbr_cycle = (int)ft_atoi_base_max(tab[i], 10);
			i++;
		}
	}
	return (i);
}

int		cw_load_settings(t_setting *setting, int ac, char **av)
{
	int		i;

	i = 1;
	if ((i = cw_init_dump(setting, ac, av, i)) % 2 != 1)
		return (0);
	while ((i = cw_init_champ(setting, ac, av, i)) < ac && i != -1);
	return (i);
}
