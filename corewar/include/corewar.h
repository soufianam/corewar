/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:20:12 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/10 12:54:27 by blefeuvr         ###   ########.fr       */
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
# define NL(x) N(x); L("")
// ---------- //
# define OP_TAB_SIZE 17

typedef struct		s_champion
{
	int				id;
	char			*name;
	char			*bin;
	int				size_prog;
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

typedef enum		e_err
{
	ERR_UNKNOW,
	ERR_USAGE,
	ERR_MALLOC,
	ERR_PLAYER_NB
}					t_err;

typedef enum	e_bool
{
	FALSE = 0,
	TRUE = 1
}				t_bool;

typedef struct	s_op
{
	int			(*f)();
	int8_t		nb_param;
	int8_t		opcode;
	int			nb_cycle;
	t_bool		codage;
}				t_op;

extern t_op		optab[OP_TAB_SIZE];
/*
** Fcts to load and check all the settings from corewar
*/
int			cw_load_settings(t_setting *setting, int ac, char **av);
int			cw_load_champion(t_setting *setting, char *file, int i, int id);
void		cw_init_setting(t_setting *setting);
int			cw_init_dump(t_setting *setting, int ac, char **av);
int			cw_init_champion(t_setting *setting, int ac, char **av, int i);
int			cw_init_champion_id(t_setting *setting);
int			cw_check_champion_id(t_setting *setting, int id);
char		*cw_read_champion_header(int fd, int *size);
char		*cw_read_champion_prog(int fd, char *bin, int prog_size, int *size);
int			cw_check_bin_header(char *bin);
int			cw_check_bin_null(char *bin, int pos);
void		cw_load_bin_champion(t_champion *champ, char *bin, int size, int id);
int			cw_strisdig(char *str);
int			cw_check_cor_file(char *file);

void		cw_exec_process(t_vm *vm, t_process *process);
int			cw_error_custom(char *str);
void		cw_create_process(t_vm *vm);
void		cw_vm_init(t_vm *vm, int ac, char **av);
void		cw_error(int err);
void		cw_core_loop(t_vm vm);
void		cw_process_process(t_list *process, t_vm *vm, int cycle);
void		cw_check_process(t_vm *vm);
void		cw_dump_and_quit(t_vm *vm);
void		cw_game_over(t_vm *vm);
char		*cw_itoa_base(char n, char *base);
t_champion	*cw_find_player(t_setting *setting, int index);
int			cw_live(t_vm *vm, t_process *process);
int			cw_ld(t_vm *vm, t_process *process);
int			cw_st(t_vm *vm, t_process *process);
int			cw_sti(t_vm *vm, t_process *process);
int			cw_and(t_vm *vm, t_process *process);
int			cw_zjump(t_vm *vm, t_process *process);
int			cw_get_1(char *vm);
int			cw_get_2(char *vm);
int			cw_get_4(char *vm);
int			cw_check_reg(int param);
void		cw_rev_get(char *registries, int nb);
int			cw_read_ocp(t_vm *vm, t_process *process, int *param,
		unsigned char ocp_trunc);
int			cw_read_ocp_short(t_vm *vm, t_process *process, int *param,
		unsigned char ocp_trunc);
int			cw_read_ocp_sh_nomod(t_vm *vm, t_process *process, int *param,
		unsigned char ocp_trunc);
int			cw_read_ocp_nomod(t_vm *vm, t_process *process, int *param,
		unsigned char ocp_trunc);
/**/
void		cw_dump_all(t_vm *vm);
/**/

extern t_op		op_tab[OP_TAB_SIZE];

#endif
