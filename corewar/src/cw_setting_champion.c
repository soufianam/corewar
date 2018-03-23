/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_setting_champion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:10:45 by cmaxime           #+#    #+#             */
/*   Updated: 2018/03/23 15:49:08 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_load_bin_champion(t_champion *champ, char *bin, int size, int id)
{
	int		prog_size;

	prog_size = cw_check_bin_header(bin);
	champ->id = id;
	champ->name = ft_memsub(bin, 4, 128);
	champ->bin = ft_memsub(bin, 2192, size);
	champ->size_prog = size - 2192;
}

int		cw_check_bin_header(char *bin)
{
	int				magic;
	int				prog_size;

	magic = (((unsigned int)bin[1] << 24) >> 8) | \
			(((unsigned int)bin[2] << 24) >> 16) | \
			(((unsigned int)bin[3] << 24) >> 24);
	if (magic != (int)COREWAR_EXEC_MAGIC)
		return (-1);
	if (cw_check_bin_null(bin, 132) || cw_check_bin_null(bin, 2184))
		return (-1);
	prog_size = ((unsigned int)bin[136] << 24) | \
			(((unsigned int)bin[137] << 24) >> 8) | \
			(((unsigned int)bin[138] << 24) >> 16) | \
			(((unsigned int)bin[139] << 24) >> 24);
	return (prog_size);
}

int		cw_check_bin_null(char *bin, int pos)
{
	int		i;

	i = pos;
	while (i < pos + 4)
	{
		if (bin[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*cw_read_champion_prog(int fd, char *bin, int prog_size, int *size)
{
	int		ret;
	char	buff[prog_size];

	if ((ret = read(fd, buff, prog_size)) > 0)
		bin = ft_memextend(bin, buff, 2192, 2192 + ret);
	if (ret == prog_size)
		*size = 2192 + prog_size;
	else
		*size = -1;
	return (bin);
}

char	*cw_read_champion_header(int fd, int *size)
{
	char	buff[2188];
	char	*bin;
	int		i;
	int		ret;
	int		prog_size;

	bin = NULL;
	i = 0;
	if ((ret = read(fd, buff, 2192)) == 2192)
	{
		bin = ft_memextend(bin, buff, i, ret);
		i = ret;
		if ((prog_size = cw_check_bin_header(bin)) == -1)
		{
			*size = -1;
			return (bin);
		}
		bin = cw_read_champion_prog(fd, bin, prog_size, size);
	}
	return (bin);
}
