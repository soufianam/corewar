/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:50:21 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/19 15:42:20 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

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
}
