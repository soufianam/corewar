/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:40:26 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/16 19:03:11 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/cdefs.h>
#include "op.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

static int		cw_parse_line(char *line, t_list **list)
{
	t_instruct	*ins;
	char		**instruct;
	char		**param;
	int			ret;

	if (!(ins = (t_instruct *)ft_memalloc(sizeof(t_instruct))))
		return (-1);
	instruct = 0;
	param = 0;
	if ((ret = cw_parse_label(line, &ins, &instruct)) < 0 && list == 0)
		return (ret);
	if (ret == 1)
	{
		if (!cw_parse_instruct(instruct[1], &ins, &param))
			return (-1);
	}
	else if (ret == 0)
	{
		if (!cw_parse_instruct(line, &ins, &param))
			return (-1);
	}
	if (!cw_parse_param(&ins, param))
		return (-1);
	ft_lstpush(list, (void *)ins, sizeof(t_instruct), &ft_lstpushf);
	if (instruct != 0)
		ft_strdel_splittab(instruct);
	if (param != 0)
		ft_strdel_splittab(param);
	return (1);
}

extern int		cw_parse(char *file, t_list **list)
{
	int			fd;
	int			ret;
	char		*line;

	ret = 0;
	fd = open(file, O_RDONLY);
	*list = 0;
	while (ft_gnl(fd, &line) > 0 && ret >= 0)
	{
		if (*line != '\0')
		{
			ret = cw_parse_line(line, list);
			ft_strdel((char **)&line);
		}
	}
	if (ret <= 0)
	{
		// Fonction err en appel avec le code d'erreur correspondant:
		// cw_error(ret);
		ft_putendl("error");
		return (0);
	}
	if (line)
		ft_strdel((char **)&line);
	return (1);
}
