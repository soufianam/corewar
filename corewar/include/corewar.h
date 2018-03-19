/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:49:39 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/19 18:34:44 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"

typedef struct	s_champion
{
	int		number;
	char	*name;
	int		*bin;
}				t_champion;

typedef struct	s_setting
{
	int			nbr_cycle;
	int			nbr_champion;
	t_champion	champion_tab[MAX_PLAYERS];
}				t_setting;

int				cw_strisdig(char *str);

#endif
