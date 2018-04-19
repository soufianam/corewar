/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_explode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 11:57:24 by cmaxime           #+#    #+#             */
/*   Updated: 2018/04/19 10:27:54 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		in_str(char c, char *str)
{
	int		i;

	if (c == '\0')
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(const char *str, char *c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (in_str(str[i], c))
			i++;
		else
		{
			count++;
			while (in_str(str[i], c) == 0 && str[i] != '\0')
				i++;
		}
	}
	return (count);
}

static int	ct(const char *str, char *c)
{
	int i;

	i = 0;
	while (in_str(str[i], c) == 0 && str[i] != '\0')
		i++;
	return (i);
}

static char	**explode(char const *s, char *c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!(tab = (char**)malloc(sizeof(*tab) * (count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (in_str(s[i], c))
			i++;
		else
		{
			if (!(tab[k] = (char*)malloc(sizeof(char) * (ct(s + i, c) + 1))))
				return (NULL);
			j = 0;
			while (in_str(s[i], c) == 0 && s[i] != '\0')
				tab[k][j++] = s[i++];
			tab[k++][j] = '\0';
		}
	}
	tab[k] = 0;
	return (tab);
}

extern char	**ft_strexplode(char const *s, char *c)
{
	if (!s || *s == '\0')
		return (NULL);
	else
		return (explode(s, c));
}
