#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    cleaner.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 12:14:21 by pprikazs          #+#    #+#              #
#    Updated: 2018/03/16 12:14:21 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make fclean &>/dev/null

EXT=""
	EXT=$EXT"\.o\~|"
	EXT=$EXT"\.c\~|"
	EXT=$EXT"\.h\~|"
	EXT=$EXT"\.a\~|"
	EXT=$EXT"\.sh\~|"
	EXT=$EXT"\.txt\~|"
	EXT=$EXT"\.md\~|"
	EXT=$EXT"\.html\~|"
	EXT=$EXT"\.php\~|"
	EXT=$EXT"\.cor\~|"
	EXT=$EXT"\.cor"

REG_EXT=""
	REG_EXT=$REG_EXT"[._]*.s[a-v][a-z]|"
	REG_EXT=$REG_EXT"[._]*.sw[a-p]|"
	REG_EXT=$REG_EXT"[._]s[a-v][a-z]|"
	REG_EXT=$REG_EXT"[._]sw[a-p]"

FILE=""
	FILE=$FILE"makefile\~|"
	FILE=$FILE"Makefile\~|"
	FILE=$FILE"\.gitignore\~|"
	FILE=$FILE"\.DS_Store\~|"
	FILE=$FILE"\.DS_Store|"
	FILE=$FILE"todo~"

find -E . -regex "(.*($EXT|$REG_EXT|$FILE))" -delete
