/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:55:13 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/23 17:20:14 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit_first(const char *str, char c)
{
	char	*mark;
	size_t	len;
	char	**split;
	
	if (c == '\0' || str == 0)
		return (0);
	mark = ft_strchr(str, c);
	if (*mark != c)
		return (0);
	if ((split = (char **)ft_memalloc(sizeof(char *) * (2 + 1))))
		return (0);
	len1 = ft_strlen(str) - ft_strlen(mark) - 1;
	split[1] = ft_strdup(++mark);
	split[0] = ft_strdup(str);
	ft_bzero(&(split[0][len1]);
	split[2] = 0;
	return (split);
}
