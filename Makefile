# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 17:11:42 by blefeuvr          #+#    #+#              #
#    Updated: 2018/03/21 15:20:34 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: libft corewar asm

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
	@printf "\e]1337;File=inline=1;height=15:" && base64 < ".media/coffee.gif" && printf "\a"
	@afplay -t 10 .media/coffee.mp3 &

.SUFFIXES:
.PHONY: all clean fclean re
