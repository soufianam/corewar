/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:40:26 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/20 15:11:06 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/cdefs.h>
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

static int		cw_parse_line_aux(char *line, t_list **list, t_instruct **ins)
{
	char		**instruct;
	char		**param;
	int			ret;

	instruct = 0;
	param = 0;
	if ((ret = cw_parse_label(line, ins, &instruct)) < 0 && list == 0)
		return (ret);
	if (ret == 1 && (ret = cw_parse_instruct(instruct[1], ins, &param)) < 0)
		return (ret);
	else if (ret == 0 && (ret = cw_parse_instruct(line, ins, &param)) < 0)
			return (ret);
	if ((ret = cw_parse_param(ins, param)) < 0)
		return (ret);
	if (instruct != 0)
		ft_strdel_tab(instruct);
	if (param != 0)
		ft_strdel_tab(param);
	return (1);
}

static int		cw_parse_line(char *line, t_list **list, header_t *head, int line_nb)
{
	t_instruct	*ins;
	int			ret;

	cw_parse_comment(line);
	if (*line == '\0')
		return (1);
	ft_strsanitalize(line, "\t ");
	if ((ret = cw_parse_header(line, head)) <= 0 || ret == 2)
		return (ret);
	if (!(ins = (t_instruct *)ft_memalloc(sizeof(t_instruct))))
		return (-1);
	ins->line = line_nb;
	ret = cw_parse_line_aux(line, list, &ins);
	cw_parse_update_pc(&ins, list);
	ft_lstpush(list, (void *)ins, sizeof(t_instruct), &ft_lstpushb);
//	ft_memdel((void**)ins);
	return (ret);
}

static int		cw_final_check(t_list *list)
{
	if (cw_check_duplicates_label(list) == -1)
		return (-20);   // Duplicata d'un label dans le .s
	if (cw_label_init(list) == -1)
		return (-21);   // Un label n'existe pas
	return (1);
}

extern int		cw_parse(char *file, t_list **list, header_t *head)
{
	int			fd;
	int			ret;
	char		*line;
	int			line_nb;

	ret = 0;
	fd = open(file, O_RDONLY);
	*list = 0;
	line_nb = 0;
	*(head->comment) = '\0';
	*(head->prog_name) = '\0';
	while (ft_gnl(fd, &line) > 0 && ret >= 0)
	{
		line_nb++;
		ft_putnbr(line_nb);
		ft_putstr(line);
		ret = cw_parse_line(line, list, head, line_nb);
		ft_putchar('\n');
		ft_strdel((char **)&line);
	}
	cw_display_header(*head);
	ft_lstiter(*list, &cw_display_instruct);
	if (line)
		ft_strdel((char **)&line);
	if (ret <= 0)
		return (ret);
	ret = cw_final_check(*list);
	return (ret);
}
