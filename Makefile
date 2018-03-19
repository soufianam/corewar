# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 17:11:42 by blefeuvr          #+#    #+#              #
#    Updated: 2018/03/19 17:33:08 by blefeuvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: corewar asm

libft:
	$(MAKE) -C lib/$@

corewar:
	$(MAKE) -C $@

asm:
	$(MAKE) -C $@

clean:
	$(MAKE) clean -C corewar
	$(MAKE) clean -C asm

fclean:
	$(MAKE) fclean -C corewar
	$(MAKE) fclean -C asm

coffee:

.SUFFIXES:
.PHONY: all clean fclean re
