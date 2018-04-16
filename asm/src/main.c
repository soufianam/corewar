/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:56:30 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/16 19:04:02 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "op.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];


int				main(int argc, char *argv[])
{
	t_list		*instructs;

	if (argc == 2)
	{
		cw_parse(argv[1], &instructs);
		// Ici le display de la liste chainé contenant l'ensemble des
		// instruction après le premier parsing.
		ft_lstiter(instructs, &cw_display_instruct);
	}
	return (0);
}
