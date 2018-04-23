/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:16:31 by cmaxime           #+#    #+#             */
/*   Updated: 2018/04/23 11:55:23 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*clean_spaces(char *line)
{
	char	*new;
	int		i;
	int		j;

	new = ft_strdup(line);
	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
			i++;
		while (line[i] != '\0' &&  line[i] != ' ' && line[i] != '\t')
		{
			new[j] = line[i];
			i++;
			j++;
		}
		new[j] = ' ';
		j++;
	}
	new[j - 1] = '\0';
	line = ft_strcpy(line, new);
	free(new);
	return (line);
}

char	*ft_cleaner(char *line)
{
	line = clean_spaces(line);
	return (line);
}
