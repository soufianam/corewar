/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsanitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:37:59 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/12 17:26:19 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strsanitalize(char *str, const char *car)
{
	int			i;
	int			y;

	i = 0;
	y = 0;
	while (str[y] != '\0' && ft_strchr(car, str[y]))
		y++;
	while (str[y] != '\0')
	{
		str[i] = str[y];
		i++;
		y++;
	}
	while (str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
}
