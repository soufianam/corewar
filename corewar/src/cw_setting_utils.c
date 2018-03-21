/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_setting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:24:17 by cmaxime           #+#    #+#             */
/*   Updated: 2018/03/21 19:04:02 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_check_bin_champion(char *bin, int size)
{

	return (1);
}

char	*cw_read_champion_data(int fd, int *size)
{
	char	*buff;
	char	*bin;
	int		i;
	int		ret;

	bin  = NULL;
	i = 0;
	buff = ft_memalloc(100);
	while ((ret = read(fd, buff, 100)) > 0)
	{
		bin = ft_memrealloc(bin, i + ret);
		bin = ft_memjoin(bin, buff, i, i + ret);
		buff = ft_memalloc(100);
		i += ret;
	}
	*size = i;
	return (bin);
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
