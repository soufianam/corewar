# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:26:31 by blefeuvr          #+#    #+#              #
#    Updated: 2018/04/18 13:35:28 by cmaxime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

# Compiler #
CC = gcc

# Libs #
LIB_DIR = ../lib
LFLAGS = -L$(LIB_DIR)/libft -lft

# Include #
CPPFLAGS = -Iinclude -I$(LIB_DIR)/libft/include

# Flags #
CFLAGS = -Werror -Wall -Wextra
DEBUG = no
ifeq ($(DEBUG), yes)
	CFLAGS = -g -w
endif

# Sources #
SRC_NAME = main.c \
		   ft_explode.c \
		   cw_write.c \
		   cw_label_init.c \
		   cw_prog_init.c \
		   cw_err.c \
		   cw_display.c \
		   cw_global.c \
		   cw_parse.c \
		   cw_parse_inst.c \
		   cw_parse_label.c \
		   cw_parse_param.c \
		   cw_parse_param_aux.c \
		   cw_parse_update_pc.c

SRC = $(addprefix /,$(SRC_NAME))

# Objects #
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

VPATH = ./src/:./src/parser/:./src/error/:

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
