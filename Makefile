# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 08:57:51 by dpetrov           #+#    #+#              #
#    Updated: 2016/12/08 10:01:21 by dpetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

IN		= -I./includes/

OBJ_PATH = ./obj/
SRC_PATH = ./src/

SRCS	= ft_printf.c functions.c convert.c
SRC     = $(addprefix $(SRC_PATH),$(SRCS))

OBJS    = $(SRCS:.c=.o)
OBJ		= $(addprefix $(OBJ_PATH),$(OBJS))

LFLAGS  = -L./libft/ -lft

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mFT_PRINTF:\t\t:BUILDED\033[0m"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(IN) -c $<
	@mv $(OBJS) $(OBJ_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[32mFT_PRINTF:\t\t:CLEANED\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mFT_PRINTF:\t\t:FULL CLEANED\033[0m"

re: fclean all
