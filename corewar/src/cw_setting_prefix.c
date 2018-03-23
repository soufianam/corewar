/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_setting_prefix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:08:09 by cmaxime           #+#    #+#             */
/*   Updated: 2018/03/23 15:55:16 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_strtab_len(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	destroy_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		cw_check_cor_file(char *file)
{
	char	**tab;
	int		i;

	tab = ft_strsplit(file, '.');
	i = ft_strtab_len(tab);
	if (i < 2)
	{
		destroy_tab(tab);
		return (1);
	}
	if (ft_strcmp(tab[i - 1], "cor") != 0)
	{
		destroy_tab(tab);
		return (1);
	}
	return (0);
}
