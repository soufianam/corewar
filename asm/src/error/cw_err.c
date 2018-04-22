/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:50:55 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/20 17:26:01 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Error Code List :
**
** code = -1 => Message = Alocation error;
**
** code = -2 => Message = Double définition du nom de programme
**		fichier = cw_parse_header => line = 72
** code = -3 => Message = Flag .name définit mais pas de définition
**		fichier = cw_parse_header => line = 50
** code = -4 => Message = Nom de programme trop long
**		fichier = cw_parse_header => line = 77
** code = -5 => Message = Double définition de commentaire
**		fichier = cw_parse_header => line = 91
** code = -6 => Message = Commentaire trop long
**		fichier = cw_parse_header => line = 96
** code = -7 => Message = Pas de .comment ou pas de .name
**		fichier = cw_parse_header => line = 118
**
** code = -8 => Message = Erreur lexical, la ligne commence par un :
**		fichier = cw_parse_label => line = 85
** code = -9 => Message = Erreur lexical, mauvais caractere dans le label;
**		fichier = cw_parse_label => line = 89
**
** code = -10 => Message = Pas d'instruction
**		fichier = cw_parse_inst => line = 85
** code = -11 => Message = L'instruction n'existe pas
**		fichier = cw_parse_inst => line = 86
**
** code = -12 => Message = Plus de paramettre que ce que l'instruction accepte.
**		fichier = cw_parse_param => line = 49
**
**
**
**
**
**
**
**
** code = -22 => Message =  Duplicata de label dans le .s.
**		fichier = cw_parse => line = 71
** code = -23 =>  Un label n'existe pas.
**		fichier = cw_parse => line = 73
*/

extern void			cw_error(int err_code, t_list *last)
{
	if (last == 0)
		ft_putendl("empty list");
	(void)err_code;
}
