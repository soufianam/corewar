/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:38:16 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/12 16:55:44 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm.h"

char		**ft_strsplit_first(const char *str, char c)
{
	char	*mark;
	size_t	len1;
	size_t	len2;
	char	**split;
	
	if (c == '\0' || str == 0)
		return (0);
	mark = ft_strchr(str, c);
	if (*mark != c)
		return (0);
	if (!(split = (char **)ft_memalloc(sizeof(char *) * (2 + 1))))
		return (0);
	len1 = ft_strlen(mark);
	len2 = ft_strlen(str) - len1;
	split[1] = ft_strdup(++mark);
	split[0] = ft_strdup(str);
	split[0][len2] = '\0';
	split[2] = 0;
	return (split);
}

char			ft_carchr(char *line, char *c)
{
	int		i;
	int		j;

	i = 0;
	while (line[i] != '\0')
	{
		j = 0;
		while (c[j] != '\0')
		{
			if (line[i] == c[j])
				return (c[j]);
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
	while (label[i] != '\0')
	{
		if(!ft_isalnum(label[i]))
		{
			if (label[i] != '_')
				return (0);
		}
		i++;
	}
	return (1);
}

int			ft_parse_label(char *line, t_instruct **inst, char ***lab)
{
	if (line[0] == '\t' || line[0] == ' ')
		return (0);
	if (ft_carchr(line, ",\t:") == ':')
	{
		*lab = ft_strsplit_first(line, ':');
		if (!ft_check_label((*lab)[0]))
			return (-1);
		(*inst)->label = ft_strdup((*lab)[0]);
		return (1);
	}
	return (-1);
}
