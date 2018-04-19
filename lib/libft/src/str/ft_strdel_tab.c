/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_splittab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:43:35 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/19 10:18:37 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

extern void			ft_strdel_tab(char **svg)
{
	int				i;

	i = 0;
	while (svg[i] != 0)
	{
		ft_strdel(&svg[i]);
		i++;
	}
	free(svg);
}
