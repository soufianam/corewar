/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_setting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:26:21 by cmaxime           #+#    #+#             */
/*   Updated: 2018/04/09 12:20:41 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_init_setting(t_setting *setting)
{
	setting->nbr_cycle = -1;
	setting->nbr_champion = 0;
}

int		cw_init_dump(t_setting *setting, int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 2 && ft_strcmp(av[1], "-dump") == 0)
	{
		i++;
		if (cw_strisdig(av[2]))
		{
			setting->nbr_cycle = (int)ft_atoi(av[2]);
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

	size_bin = 0;
	if (cw_check_cor_file(file) == 1)
		cw_error_custom("Error: not a .cor file");
	if ((fd = open(file, O_RDONLY)) == -1)
		cw_error_custom("Error: can't read file");
	bin = cw_read_champion_header(fd, &size_bin);
	if (!bin || size_bin == -1 || cw_check_champion_id(setting, id) == -1)
	{
		if (bin)
			free(bin);
		cw_error_custom("Error: bad file format");
	}
	cw_load_bin_champion(&(setting->champion_tab[setting->nbr_champion]), \
			bin, size_bin, id);
	setting->nbr_champion += 1;
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
			cw_error(ERR_USAGE);
	}
	else if (i < ac)
	{
		i = cw_load_champion(setting, av[i], i, cw_init_champion_id(setting));
	}
	else
		cw_error(ERR_USAGE);
	return (i);
}

int		cw_load_settings(t_setting *setting, int ac, char **av)
{
	int		i;

	cw_init_setting(setting);
	i = cw_init_dump(setting, ac, av);
	if (i != 1 && i != 3)
		cw_error(ERR_USAGE);
	while (i < ac && i != -1)
		i = cw_init_champion(setting, ac, av, i);
	if (setting->nbr_champion > MAX_PLAYERS)
		cw_error_custom("Error: too many champions");
	else if (setting->nbr_champion <= 0)
		cw_error_custom("Error: no champion");
	return (i);
}
