# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 08:57:51 by dpetrov           #+#    #+#              #
#    Updated: 2016/12/02 09:40:40 by dpetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= print

CC		=  gcc -Wall -Wextra -Werror -I./includes/

OBJ_PATH = ./obj/
SRC_PATH = ./src/

SRCS	= main.c ft_printf.c
SRC     = $(addprefix $(SRC_PATH),$(SRCS))

OBJS    = $(SRCS:.c=.o)
OBJ		= $(addprefix $(OBJ_PATH),$(OBJS))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L./libft -lft

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	    @mkdir -p $(OBJ_PATH)
		@$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@
clean:
	rm -rf $(NAME)

re: clean all
