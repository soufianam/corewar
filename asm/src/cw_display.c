/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:50:32 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/17 15:04:18 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/cdefs.h>
#include "ft_printf.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

/*
** Display de la structure global passé en ressource du projet
*/
extern void		cw_display_optab(void)
{
	int			i;

	i = 0;
	while (i < OP_TAB_SIZE)
	{
		ft_printf("ins : %s | nb_param : %d | ", optab[i].ins, optab[i].nb_param);
		ft_printf("params : {p1 %d , p2 %d, ", optab[i].param[0], optab[i].param[1]);
		ft_printf("p3 %d, p4 %d} | ", optab[i].param[2], optab[i].param[3]);
		ft_printf("opcode : %d | ", optab[i].opcode);
		ft_printf("nb_cycle : %d | ", optab[i].nb_cycle);
		ft_printf("desc : %s | ", optab[i].desc);
		ft_printf("carry : %d | codage : %d \n", optab[i].carry, optab[i].codage);
		i++;
	}
}

/*
** Display d'un maillon de la list chainée contenant l'intégralité des
** instructions, après un premier formatage du fichier .s.
** Usage:
** 		ft_lstiter(instructs, &ft_display_instruct);
*/

extern void		cw_display_instruct(t_list *elem)
{
	t_instruct *content;

	content = ((t_instruct *)elem->content);
	ft_putstr("label : ");
	(content->label != 0) ? ft_putstr(content->label) : ft_putnbr(0);
	ft_putstr(" | pc : ");
	ft_putnbr(content->pc);
	ft_putstr(" | id : ");
	ft_putnbr(content->id);
	ft_putstr(" | ocp : ");
	ft_putbit((void *)&(content->ocp), sizeof(unsigned char));

	ft_putstr(" | params : link(");
		ft_putstr(content->param[0].link);
		ft_putstr(") val(");
		ft_putnbr(content->param[0].val);
		ft_putstr(") pid(");
		ft_putnbr(content->param[0].pid);
	ft_putstr(") | link(");
		ft_putstr(content->param[1].link);
		ft_putstr(") val(");
		ft_putnbr(content->param[1].val);
		ft_putstr(") pid(");
		ft_putnbr(content->param[1].pid);
	ft_putstr(") | link(");
		ft_putstr(content->param[2].link);
		ft_putstr(") val(");
		ft_putnbr(content->param[2].val);
		ft_putstr(") pid(");
		ft_putnbr(content->param[2].pid);
	ft_putendl(")\n");
}
