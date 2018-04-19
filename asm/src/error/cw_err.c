/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:50:55 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/19 10:47:02 by pprikazs         ###   ########.fr       */
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

extern void			cw_error(int err_code, int line_nb)
{
	(void)err_code;
	(void)line_nb;
}
