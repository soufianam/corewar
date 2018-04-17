/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:56:30 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/17 18:08:03 by cmaxime          ###   ########.fr       */
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
	char		*bin;
	int			size;

	bin = NULL;
	if (argc == 2)
	{
		cw_parse(argv[1], &instructs);
		// Ici le display de la liste chainé contenant l'ensemble des
		// instruction après le premier parsing.
		if (cw_check_duplicates_label(instructs) == -1)
		{
			ft_putendl("Double label");
			return (0);
		}
		if (cw_label_init(instructs) == -1)
		{
			ft_putendl("label error");
			return (0);
		}
		ft_putendl("OK END");
		if ((size = cw_prog_init(instructs, &bin)) == -1)
		{
			ft_putendl("prog error");
			return (0);
		}
		ft_putnbr(size); ft_putendl("");
		ft_lstiter(instructs, &cw_display_instruct);
	}
	return (0);
}
