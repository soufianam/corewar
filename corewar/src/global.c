/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:33:56 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/18 12:33:57 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_op    op_tab[] =
{
	{cw_live, 1, 1, 10, 0},
	{cw_ld, 2, 2, 5, 0},
	{cw_st, 2, 3, 5, 0},
	{cw_and, 3, 6, 6, 0},
	{cw_zjump, 1, 9, 20, 1},
	{cw_sti, 3, 11, 25, 1},
	{cw_add, 3, 4, 10, 0},
	{cw_sub, 3, 5, 10, 0},
	{cw_or, 3, 7, 6, 0},
	{cw_xor, 3, 8, 6, 0},
	{cw_ldi, 3, 10, 25, 1},
	{cw_fork, 1, 12, 800, 1},
	{cw_lld, 2, 13, 10, 0},
	{cw_lldi, 3, 14, 50, 1},
	{cw_lfork, 1, 15, 1000, 1},
	{cw_aff, 1, 16, 2, 0}
};
