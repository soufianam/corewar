/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_setting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:24:17 by cmaxime           #+#    #+#             */
/*   Updated: 2018/03/22 12:54:50 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_check_bin_header(char *bin)
{
	int		magic;

	magic = ((int)(bin[0]) << 24) + ((int)(bin[1]) << 16) \
			+ ((int)(bin[2]) << 8) + (int)(bin[3]);
	if (magic != COREWAR_EXEC_MAGIC)
		return (-1);
   	return (1);
}

int		cw_check_bin_champion(char *bin, int size)
{
	int		prog_size;

	if (size < 4092)
		return (-1);
	if ((prog_size = cw_check_bin_header(bin)) < 0)
		return (-1);
	return (1);
}

char	*ft_memextend(char *dst, char *src, size_t sz_d, size_t sz_s)
{
	char	*tmp;

	dst = ft_memrealloc(dst, sz_d + sz_s);
	tmp = dst + sz_d;
	tmp = ft_memcpy(tmp, src, sz_s);
	return (dst);
}

char	*cw_read_champion_data(int fd, int *size)
{
	char	buff[100];
	char	*bin;
	int		i;
	int		ret;

	bin  = NULL;
	i = 0;
	while ((ret = read(fd, buff, 100)) > 0)
	{
		bin = ft_memextend(bin, buff, i, ret);
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
