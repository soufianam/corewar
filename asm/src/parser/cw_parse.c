/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:40:26 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/19 10:22:04 by pprikazs         ###   ########.fr       */
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

static int		cw_parse_line(char *line, t_list **list)
{
	t_instruct	*ins;
	int			ret;

	if (!(ins = (t_instruct *)ft_memalloc(sizeof(t_instruct))))
		return (-1);
	if ((ret = cw_parse_line_aux(line, list, &ins)) < 0)
		return (ret);
	cw_parse_update_pc(&ins, list);
	ft_lstpush(list, (void *)ins, sizeof(t_instruct), &ft_lstpushb);
//	ft_memdel((void**)ins);
	return (1);
}

char			*ft_getstr_head(char *line)
{
	char	*buff;
	int		start;
	int		end;

	start = 0;
	while (line[start] != '"' && line[start] != '\0')
		start++;
	if (line[start] == '\0')
	{
		free(line);
		return (NULL);
	}
	end = start + 1;
	while (line[end] != '"' && line[end] != '\0')
		end++;
	if (line[end] != '"')
	{
		free(line);
		return (NULL);
	}
	buff = (char*)ft_memalloc(sizeof(char) * (end - start + 1));
	buff = ft_strncpy(buff, line + start + 1, end - start - 1);
	free(line);
	return (buff);
}

static int		cw_parse_header(char *line, header_t *head)
{
	char	**tab;
	char	*buff;

	(void)head;
	tab = ft_strexplode(line, "#");
	buff = ft_strdup(*tab);
	ft_strdel_tab(tab);
	tab = ft_strexplode(buff, "\t ");
	if (*tab && ft_strcmp(NAME_CMD_STRING, *tab) == 0 && tab[1])
	{
		ft_strdel_tab(tab);
		buff = ft_getstr_head(buff);
		ft_strcpy(head->prog_name, buff);
		if (buff)
			free(buff);
		return (0);
	}
	if (*tab && ft_strcmp(COMMENT_CMD_STRING, *tab) == 0 && tab[1])
	{
		ft_strdel_tab(tab);
		buff = ft_getstr_head(buff);
		ft_strcpy(head->comment, buff);
		free(buff);
		return (1);
	}
	return (-1);
}

extern int		cw_parse(char *file, t_list **list, header_t *head)
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
			ret = (ret == 0) ? cw_parse_header(line, head) 
				: cw_parse_line(line, list); 
			//Mettre à la norme la fonction, ajout du parsing des commentaire.
											 //Ajout du parsing de l'entête.
											 //cw_parse(char *file, t_list **list, header_t **head);
											 //cw_parse_line(char *file, t_list **list, header_t **head);
			ft_strdel((char **)&line);
		}
	}
	// functions de maxime ici pour les labels
	if (cw_check_duplicates_label(*list) == -1)
		ret = -20;   // Duplicata d'un label dans le .s
	if (cw_label_init(*list) == -1)
		ret = -21;   // Un label n'existe pas
	if (line)
		ft_strdel((char **)&line);
	if (ret <= 0) // Peut etre viré
		ft_putendl("error");
	return (ret);
}
