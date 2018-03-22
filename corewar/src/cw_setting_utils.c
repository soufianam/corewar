/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_setting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:24:17 by cmaxime           #+#    #+#             */
/*   Updated: 2018/03/22 16:07:26 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*ft_memsub(char *src, size_t start, size_t size)
{
	char	*new;
	size_t	i;

	new = ft_memalloc(size);
	i = start;
	while (i < start + size)
	{
		new[i - start] = src[i];
		i++;
	}
	return (new);
}

char	*ft_memextend(char *dst, char *src, size_t sz_d, size_t sz_s)
{
	char	*tmp;

	dst = ft_memrealloc(dst, sz_d + sz_s);
	tmp = dst + sz_d;
	tmp = ft_memcpy(tmp, src, sz_s);
	return (dst);
}

int		cw_check_champion_id(t_setting *setting, int id)
{
	int		i;
	
	i = -1;
	while (++i < setting->nbr_champion)
	{
		if (id == setting->champion_tab[i].id)
			return (1);
		i++;
	}
	return (0);
}

int		cw_init_champion_id(t_setting *setting)
{
	int		max_id;
	int		i;
	
	if (setting->nbr_champion == 0)
		return (1);
	max_id = setting->champion_tab[0].id;
	i = 0;
	while (++i < setting->nbr_champion)
	{
		max_id = max_id >= setting->champion_tab[i].id ? max_id : \
				 setting->champion_tab[i].id;
		i++;
	}
	return (max_id + 1);
}

int		cw_strisdig(char *str)
{
	int			i;
	intmax_t	conv;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
		i++;
	conv = ft_atoi_base_max(str, 10);
	if (i > 11 || conv > INT_MAX || conv < INT_MIN)
		return (0);
	if (str[i] == '\0' && i != 0)
		return (1);
	return (0);
}
