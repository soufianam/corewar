/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_setting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:26:21 by cmaxime           #+#    #+#             */
/*   Updated: 2018/03/22 16:14:17 by cmaxime          ###   ########.fr       */
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
		if (i < ac && cw_strisdig(av[i]))
		{
			setting->nbr_cycle = (int)ft_atoi(av[i]);
			i++;
		}
	}
	return (i);
}

int		cw_load_champion(t_setting *setting, char *file, int i, int id)
{
	int		fd;
	int		size_bin;
	char	*bin;

	id = 0;
	size_bin = 0;
	if (cw_check_cor_file(file) == 1)
		return (-1);
	fd = open(file, O_RDONLY);
	bin = cw_read_champion_header(fd, &size_bin);
	if (size_bin == -1 || cw_check_champion_id(setting, id))
	{
		if (bin)
			free(bin);
		return (-1);
	}
	cw_load_bin_champion(&(setting->champion_tab[setting->nbr_champion]), \
			bin, size_bin, id);
	setting->nbr_champion++;
	free(bin);
	return (++i);
}

int		cw_init_champion(t_setting *setting, int ac, char **av, int i)
{
	if (i < ac && ft_strcmp(av[i], "-n") == 0)
	{
		i += 2;
		if (i < ac && cw_strisdig(av[i - 1]))
			i = cw_load_champion(setting, av[i], i, ft_atoi(av[i - 1]));
		else
			return (-1);
	}
	else if (i < ac)
	{
		i = cw_load_champion(setting, av[i], i, cw_init_champion_id(setting));
	}
	else
		return (-1);
	return (i);
}

int		cw_load_settings(t_setting *setting, int ac, char **av)
{
	int		i;

	i = 1;
	cw_init_setting(setting);
	if ((i = cw_init_dump(setting, ac, av, i)) % 2 != 1)
		return (0);
	while (i < ac && i != -1)
		i = cw_init_champion(setting, ac, av, i);
	return (i);
}
