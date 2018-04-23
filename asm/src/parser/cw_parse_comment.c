/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:50:21 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/23 11:29:49 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

static void		cw_trim_line(char *line)
{
	int		i;

	i = ft_strlen(line);
	while (i >= 0 && (line[i] == '\0' || line[i] == ' ' || line[i] == '\t'))
	{
		*(line + i) = '\0';
		i--;
	}
}

extern void		cw_parse_comment(char *line)
{
	char		*tmp;

	if (*line != '\0')
	{
		if (*line == COMMENT_CHAR)
			*line = '\0';
		else
		{
			tmp = ft_strchr(line, COMMENT_CHAR);
			if (tmp != 0)
				*tmp ='\0';
		}
	}
	cw_trim_line(line);
}
