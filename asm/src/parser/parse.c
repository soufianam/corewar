/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:40:26 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/23 19:51:43 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/cdefs>
#include "op.c"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

int			ft_count_param(char **param)
{
	int		i;

	i = 0;
	while (param[i] != '\0')
		i++;
	return (++i);
}

int			ft_parse_line(char *line, t_list **list)
{
	t_instruct	*ins;
	char		**instruct;
	char		**param
	int			ret;

	if (!(inst = (t_instruct *)ft_memalloc(sizeof(t_instruct))))
		return (-1);
	if (ret = ft_parse_label(line, ins, instruct) == 0 && list == 0)
		return (-1);	
	if (ret = 1)
	{
		if (!ft_parse_instruct(instruct[1], ins, param))
			return (-1);
	}
	else
	{
		if (!ft_parse_instruct(line, ins, param))
			return (-1);
	}
	if (!ft_parse_param(param[1], ins))
		return (0);
	ft_strdel_splittab(ins);
	ft_strdel_splittab(param);
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
	while (ft_gnl(fd, &line) > 0 & ret != 1)
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
