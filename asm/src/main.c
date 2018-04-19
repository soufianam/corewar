/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:56:30 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/19 10:11:37 by pprikazs         ###   ########.fr       */
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
	header_t	head;

	bin = NULL;
	if (argc == 2)
	{
		cw_parse(argv[1], &instructs, &head);
		if ((size = cw_prog_builder(instructs, &bin)) < 0)
		{
			ft_putendl("prog error");
			return (0);
		}
		head.magic = COREWAR_EXEC_MAGIC;
		head.prog_size = (unsigned int)size;
		cw_write("test_max.cor", head, bin);
		//ft_lstiter(instructs, &cw_display_instruct);
	}
	return (0);
}
