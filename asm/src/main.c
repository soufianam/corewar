/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:56:30 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/23 12:21:51 by cmaxime          ###   ########.fr       */
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
	int			ret;
	header_t	head;

	bin = NULL;
	if (argc == 2)
	{
		if ((ret = cw_parse(argv[1], &instructs, &head)) < 0)
		{
			cw_error(ret, ft_lstlast(&instructs));
			//while (1);
			return (0);
		}
		if ((size = cw_prog_builder(instructs, &bin)) < 0)
		{
			ft_putendl("prog error");
			//while (1);
			return (0);
		}
		head.magic = COREWAR_EXEC_MAGIC;
		head.prog_size = (unsigned int)size;
		cw_write(argv[1], head, bin);
		//while (1);
	}
	return (0);
}
