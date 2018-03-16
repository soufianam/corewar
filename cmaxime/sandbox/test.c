/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:47:51 by cmaxime           #+#    #+#             */
/*   Updated: 2018/03/16 15:18:58 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#define COREWAR_EXEC_MAGIC		0xea83f3
#define PROG_NAME_LENGTH		(128)
#define COMMENT_LENGTH			(2048)

typedef struct		header_s
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					header_t;

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

void	cw_write_header(header_t h, int fd)
{
	cw_write_uint(fd, h.magic);
	cw_write_str(fd, h.prog_name, 128);
	cw_write_null(fd, 4);
	cw_write_uint(fd, h.prog_size);
	cw_write_str(fd, h.comment, 2048);
	cw_write_null(fd, 4);
	write(1, "d", 1);
}

int		main(int ac, char **av)
{
	int		fd;
	header_t	header;

	if (ac == 4)
	{
		header.magic = COREWAR_EXEC_MAGIC;
		strcpy(header.prog_name, av[2]);
		header.prog_size = 2048;
		strcpy(header.comment, av[3]);
		fd = open(av[1], O_WRONLY, O_CREAT, O_APPEND);
		cw_write_header(header, fd);
	}
	return (0);
}
