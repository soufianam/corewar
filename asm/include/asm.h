/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:09:49 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/21 18:18:28 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

typedef struct	s_param
{
	char	pid;
	int		val;
	char	*link;
}				t_param;

typedef struct	s_instruct
{
	char	*label;
	int		pc;
	char	id;
	char	ocp;
	t_param	param[3];
}				t_instruct;

#endif
