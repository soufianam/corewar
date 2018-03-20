/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:49:39 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/20 16:07:36 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
//# include "struct_corewar.h"

// A commenter //
# define L(x) ft_putendl_fd(x, 1)
# define S(x) ft_putstr_fd(x, 1)
# define N(x) ft_putnbr_fd(x, 1)
# define C(x) ft_putchar_fd(x, 1)
# define ND(x, y) N(x); S(" - "); N(y); L("")
// ---------- //

typedef struct		s_champion
{
	int				number;
	char			*name;
	int				*bin;
}					t_champion;

typedef struct		s_process
{
	char			registries[REG_NUMBER][REG_SIZE]; //r1 = player id
	int				pc; //entrypoint du processus
	int				carry; //init a 0
	int				next_cycle; //init a 0
}					t_process;

typedef struct		s_setting
{
	int				nbr_cycle;
	int				nbr_champion;
	t_champion		champion_tab[MAX_PLAYERS];
}					t_setting;

typedef struct		s_vm
{
	t_setting		settings;
	int				cycle;
	t_list			*process; //all process list
	int				*vm;
}					t_vm;

int					cw_strisdig(char *str); // a supprimer ?

#endif
