# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 16:59:23 by blefeuvr          #+#    #+#              #
#    Updated: 2018/03/23 12:14:12 by blefeuvr         ###   ########.fr        #
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
			cw_create_process.c 
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
