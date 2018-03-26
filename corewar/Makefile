# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 16:53:34 by tdeborde          #+#    #+#              #
#    Updated: 2018/03/26 15:11:05 by tdeborde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

# Compiler #
CC = gcc

# Libs #
LIB_DIR = ../lib
LFLAGS = -L$(LIB_DIR)/libft -lft

# Include #
CPPFLAGS = -Iinclude -I$(LIB_DIR)/libft/include

# Flags #
CFLAGS = -Werror -Wall -Wextra

# Sources #
SRC_NAME =	main.c \
			global.c \
			cw_process.c \
			cw_check.c \
			cw_core_loop.c \
			cw_error.c \
			cw_end.c \
			cw_setting_utils.c \
			cw_setting_champion.c \
			cw_setting_init.c \
			cw_setting_prefix.c \
			cw_vm_init.c \
			cw_op_utils.c \
			cw_op_utils2.c \
			cw_create_process.c \
			cw_live.c \
			cw_ld.c \
			cw_st.c \
			cw_sti.c \
			cw_and.c \
			cw_zjump.c
SRC = $(addprefix /,$(SRC_NAME))

# Objects #
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

VPATH = src src/instructions

# Deps #
DEPS = include/*.h Makefile 
DEPS += $(shell find $(LIB_DIR) -type f -regex ".*\.[ch]")

# Rules #
.PHONY: all, clean, fclean, re
.SUFFIXES:

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	$(MAKE) -C $(LIB_DIR)/libft
	$(CC) $(LFLAGS) $(OBJ) -o $@

$(OBJ_PATH)%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(LIB_DIR)/libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIB_DIR)/libft

re:
	$(MAKE) fclean
	$(MAKE) all
