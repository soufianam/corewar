/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 12:11:09 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/19 15:23:00 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

/*
** A supprimer de gnl a ajouter dans la libft
*/
extern int		cw_strextend(char **str, char *tmp)
{
	char	*cpy;
	int		len;

	if (*str == NULL)
	{
		*str = ft_strdup(tmp);
		return (1);
	}
	len = ft_strlen(*str);
	if (!(cpy = ft_strnew(sizeof(char) * len + 1)))
		return (0);
	ft_memcpy((void *)cpy, (void *)*str, sizeof(char) * (len + 1));
	ft_memdel((void **)str);
	*str = ft_strjoin(cpy, tmp);
	ft_memdel((void **)&cpy);
	return (1);
}

static char			ft_getstr_head(char *line, char **buff)
{
	int				start;
	int				end;

	start = 0;
	if (*buff == 0)
	{
		while (line[start] != '"' && line[start] != '\0')
			start++;
		if (line[start] == '\0')
			return (-1);
	}
	end = (start != 0) ? start + 1 : 0;
	while (line[end] != '"' && line[end] != '\0')
		end++;
	if (cw_strextend(buff, &line[start]) == 0)
	{
		if (*buff)
			ft_strdel(buff);
		return (-1); // Allocation error
	}
	if (line[end] == '\0')
		return (0);
	return (1);
}

static int		cw_parse_header_checkname(char *line, header_t *head, char *buff, int *stat)
{
		int		ret;

		*stat = 1;
		if (*(head->prog_name) != '\0')
			return (-1); //Double définition du nom de programme.
		ret = ft_getstr_head(line, &buff);
		if (ret > 0)
		{
			if (ft_strlen(buff) > PROG_NAME_LENGTH)
				return (-1); //Nom de programme trop long
			ft_strcpy(head->prog_name, buff);
			ft_strdel((char **)&buff);
			stat = 0;
		}
		return (ret);
}

static int		cw_parse_header_checkcomment(char *line, header_t *head, char *buff, int *stat)
{
		int		ret;

		*stat = 2;
		if (*(head->comment) != '\0')
			return (-1); //Double définition du commentaire..
		ret = ft_getstr_head(line, &buff);
		if (ret > 0)
		{
			if (ft_strlen(buff) > COMMENT_LENGTH)
				return (-1); //Comment lenght trop long
			ft_strcpy(head->comment, buff);
			ft_strdel((char **)&buff);
			stat = 0;
		}
		return (ret);
}

extern int		cw_parse_header(char *line, header_t *head)
{
	static char	*buff = 0;
	static int	stat = 0;
	int			ret;

	ret = 1;
	if (!!ft_strncmp(NAME_CMD_STRING, line, ft_strlen(NAME_CMD_STRING)) || \
			stat == 1)
		ret = cw_parse_header_checkname(line, head, buff, &stat);
	else if (!!ft_strncmp(COMMENT_CMD_STRING, line, \
				ft_strlen(COMMENT_CMD_STRING)) || stat == 2)
		ret = cw_parse_header_checkcomment(line, head, buff, &stat);
	return (ret);
}
