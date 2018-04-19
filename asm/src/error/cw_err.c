/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:50:55 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/19 11:11:47 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Error Code List :
**
** -20 Duplicata de label dans le .s.
** -21 Un label n'existe pas.
**
*/

extern void			cw_error(int err_code, t_list *last)
{
	if (last == 0)
		ft_putendl("empty list");
	(void)err_code;
}
