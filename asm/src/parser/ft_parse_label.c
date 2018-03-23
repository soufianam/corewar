/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:38:16 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/23 17:39:00 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm.h"

char			ft_carchr(char *line, char *c)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		j = 0;
		while (c[j] != '\0')
		{
			if (line[i] == c[j])
				return (c);
			j++;
		}
		i++;
	}
	return (line[i]);
}

int			ft_check_label(char *label)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if(!ft_isalnum(str[i]))
		{
			if (str[i] != '_')
				return (0)
		}
		i++;
	}
	return (1);
}

int			ft_parse_label(char *line, t_instruct *inst, char **lab)
{
	if (line[0] == '\t' || line[0] == ' ')
		return (0);
	if (ft_carchr(line, ",\t:") == ':')
	{
		split = ft_strsplit_first(line, ':');
		if (!ft_check_label(split[0]))
			return (0);
		inst->label = ft_strdup(split[0]);
		return (1);
	}
	return (0);
}
