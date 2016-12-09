# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 08:57:51 by dpetrov           #+#    #+#              #
#    Updated: 2016/12/09 14:11:14 by dpetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= print

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

IN		= -I./includes/

OBJ_PATH = ./obj/
SRC_PATH = ./src/

SRCS	= ft_printf.c functions.c convert.c main.c
SRC     = $(addprefix $(SRC_PATH),$(SRCS))

OBJS    = $(SRCS:.c=.o)
OBJ		= $(addprefix $(OBJ_PATH),$(OBJS))

LFLAGS  = -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCDIR) -o $(NAME) $(OBJ) $(LFLAGS)
	@echo "\033[32mFT_PRINTF:\t\t:BUILDED\033[0m"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(IN) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[32mFT_PRINTF:\t\t:CLEANED\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mFT_PRINTF:\t\t:FULL CLEANED\033[0m"

re: fclean all
