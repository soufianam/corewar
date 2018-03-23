/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:40:26 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/23 15:44:42 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "op.c"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

int			ft_parse_line(char *line, t_list **list)
{
	t_instruct	*inst;
	char		**split;
	int			i;

	if (!(inst = (t_instruct *)ft_memalloc(sizeof(t_instruct))))
		return (0);
	i = 0;
	split = ft_strsplit(line, ':');
	ft_putstr(split[0]);
	ft_putstr("    ....   ");
	ft_putchar('\n');

	(void)list;
	(void)inst;
	return (1);
}

int				parse(char	*file)
{
	int			fd;
	int			ret;
	char		*line;
	t_list		*list;

	ret = 1;
	fd = open(argv[1], O_RDONLY);
	while (ft_gnl(fd, &line) > 0)
	{
		ret = ft_parse_line(line, &list);
		ft_strdel((char **)&line);
	}
	if (line)
		ft_strdel((char **)&line);
	if (ret <= 0)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}
