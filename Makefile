# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 09:37:16 by dpetrov           #+#    #+#              #
#    Updated: 2017/01/06 15:44:14 by dpetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

CC		= -gcc -Wall -Wextra -Werror

SRCS	= main.c list_dir.c inspect_file.c
SRC_PATH	= srcs/
SRC		= $(addprefix $(SRC_PATH), $(SRCS))

.PHONY: all clean fclean re

all:
	@$(CC) -I./includes/ $(SRC) -o $(NAME)
	@echo "\033[32mFT_LS:\t\t:BUILDED\033[0m"

clean:

fclean:
	@rm -r $(NAME)
	@echo "\033[32mFT_LS:\t\t:FUlL CLEANED\033[0m"

re: fclean all
