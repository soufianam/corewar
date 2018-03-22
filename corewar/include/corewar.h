/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:29:49 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/22 12:58:03 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <limits.h>
# include <fcntl.h>

# include "libft.h"
# include "op.h"
//# include "struct_corewar.h"

// ---------- //
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
	char			*bin;
}					t_champion;

typedef struct		s_process
{
	char			registries[REG_NUMBER][REG_SIZE]; //r1 = player id
	int				entrypoint; //entrypoint
	int				pc; //init a 0
	int				carry; //init a 0
	int				next_cycle; //init a 0
	int				live; //init a 0
}					t_process;

typedef struct		s_setting
{
	int				nbr_cycle;
	int				nbr_champion;
	t_champion		champion_tab[MAX_PLAYERS];
}					t_setting;

typedef struct		s_live
{
	int				index; //init -1
	unsigned int	cycle; //init -1
}					t_live;

typedef struct		s_loop
{
	int				cycle_to_die;
	int				next_cycle_to_die;
	int				next_max_check;
	t_live			last_live;
}					t_loop;

typedef struct		s_vm
{
	t_setting		setting;
	int				cycle;
	t_list			*process; //all process list
	char			*vm;
	t_loop			loop;
}					t_vm;

typedef enum	e_err
{
	ERR_PARAM,
	ERR_MALLOC
} t_err;

int		cw_load_settings(t_setting *setting, int ac, char **av);
char    *cw_read_champion_data(int fd, int *size);
int     cw_check_bin_champion(char *bin, int size);
int		cw_strisdig(char *str);

void	cw_vm_init(t_vm *vm, int ac, char **av);
void    cw_error(int err);
void    cw_core_loop(t_vm vm);
void    cw_process_process(t_list *process, char *vm, int cycle);
void    cw_check_process(t_vm *vm);
void    cw_dump_and_quit(t_vm *vm);
void    cw_game_over(t_vm *vm);

#endif
