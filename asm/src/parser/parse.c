/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:40:26 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/12 17:28:39 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/cdefs.h>
#include "op.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

int			ft_parse_line(char *line, t_list **list)
{
	t_instruct	*ins;
	char		**instruct;
	char		**param;
	int			ret;

	if (!(ins = (t_instruct *)ft_memalloc(sizeof(t_instruct))))
		return (-1);
	instruct = 0;
	param = 0;
	if ((ret = ft_parse_label(line, &ins, &instruct)) == -1 && list == 0)
		return (-1);
	if (ret == 1)
	{
		if (!ft_parse_instruct(instruct[1], &ins, &param))
			return (-1);
	}
	else
	{
		if (!ft_parse_instruct(line, &ins, &param))
			return (-1);
	}
	if (!ft_parse_param(&ins, param))
		return (-1);
	ft_lstpush(list, (void *)ins, sizeof(t_instruct), &ft_lstpushf);
	if (instruct != 0)
		ft_strdel_splittab(instruct);
	if (param != 0)
		ft_strdel_splittab(param);
	return (1);
}

int				ft_parse(char *file)
{
	int			fd;
	int			ret;
	char		*line;
	t_list		*list;

	ret = 0;
	fd = open(file, O_RDONLY);
	list = 0;
	while (ft_gnl(fd, &line) > 0 && ret >= 0)
	{
		if (*line != '\0')
		{
			ret = ft_parse_line(line, &list);
			ft_strdel((char **)&line);
		}
	}
	ft_lstiter(list, &ft_display_instruct);
	if (ret <= 0)
	{
		ft_putendl("error");
		return (0);
	}
	if (line)
		ft_strdel((char **)&line);
	return (1);
}
