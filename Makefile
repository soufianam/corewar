# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 17:11:42 by blefeuvr          #+#    #+#              #
#    Updated: 2018/03/23 18:49:11 by blefeuvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	$(MAKE) -C lib/libft
	$(MAKE) -C corewar
	$(MAKE) -C asm

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


a:
	@touch .tmp

joke:
	@bash -c "if [ -f '.tmp' ]; then curl -s http://api.icndb.com/jokes/random | cut -d '\"' -f 12; afplay -t 10 .media/laught.mp3 & fi"
	@rm -f .tmp

.SUFFIXES:
.PHONY: all clean fclean re
