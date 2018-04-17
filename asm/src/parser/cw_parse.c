/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:40:26 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/17 12:18:57 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/cdefs.h>
#include "op.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

/*
static void		cw_instruct_del(t_instruct **ins)
{
	int			i;

	i = 0;
	ft_strdel((char **)&((*ins)->label));
	while (i < MAX_ARGS_NUMBER)
	{
		if ((*ins)->param[i].link != 0)
			ft_strdel((char **)&((*ins)->param[i].link));
		i++;
	}
}
*/
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
		ft_strdel_splittab(instruct);
	if (param != 0)
		ft_strdel_splittab(param);
	return (1);
}

static int		cw_parse_line(char *line, t_list **list)
{
	t_instruct	*ins;
	int			ret;

	if (!(ins = (t_instruct *)ft_memalloc(sizeof(t_instruct))))
		return (-1);
	if ((ret = cw_parse_line_aux(line, list, &ins)) < 0)
		return (ret);
	ft_lstpush(list, (void *)ins, sizeof(t_instruct), &ft_lstpushf);
//	cw_instruct_del(&ins);
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
		if (*line != '\0' && *line != COMMENT_CHAR)
		{
			ret = cw_parse_line(line, list); //Mettre à la norme la fonction, ajout du parsing des commentaire.
											 //Ajout du parsing de l'entête.
											 //cw_parse(char *file, t_list **list, header_t **head);
											 //cw_parse_line(char *file, t_list **list, header_t **head);
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
