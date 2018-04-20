/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:47:51 by cmaxime           #+#    #+#             */
/*   Updated: 2018/04/18 13:47:45 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	cw_write_uint(int fd, unsigned int magic)
{
	char	c;

	c = (char)(magic >> 24);
	write(fd, &c, 1);
	c = (char)(magic >> 16);
	write(fd, &c, 1);
	c = (char)(magic >> 8);
	write(fd, &c, 1);
	c = (char)magic;
	write(fd, &c, 1);
}

void	cw_write_str(int fd, char *str, int size)
{
	int		i;
	char	c;

	c = 0;
	i = strlen(str);
	write(fd, str, i);
	while (i++ < size)
		write(fd, &c, 1);
}

void	cw_write_null(int fd, int size)
{
	int		i;
	char	c;

	c = 0;
	i = 0;
	while (i++ < size)
		write(fd, &c, 1);
}

void	cw_write_header(header_t h, int fd, char *bin)
{
	cw_write_uint(fd, h.magic);
	cw_write_str(fd, h.prog_name, PROG_NAME_LENGTH);
	cw_write_null(fd, 4);
	cw_write_uint(fd, h.prog_size);
	cw_write_str(fd, h.comment, COMMENT_LENGTH);
	cw_write_null(fd, 4);
	write(fd, bin, h.prog_size);
}

int		cw_write(char *name, header_t head, char *bin)
{
	int		fd;
	char	*new_name;

	new_name = (char*)ft_memalloc(sizeof(char) * (ft_strlen(name) + 3));
	new_name = ft_strncpy(new_name, name, ft_strlen(name) - 1);
	new_name = ft_strcat(new_name, "cor");
	fd = open(new_name, O_CREAT | O_RDWR, 777);
	if (fd > 0)
		cw_write_header(head, fd, bin);
	free(new_name);
	return (0);
}
