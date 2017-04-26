# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 15:37:16 by jerasmus          #+#    #+#              #
#    Updated: 2017/01/09 11:56:47 by jerasmus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Werror -Wextra -g

SRC = main.c ft_getline.c ft_loop.c ft_echo.c ft_getenv.c ft_quotes.c \
	  ft_args.c ft_cd.c ft_env.c ft_fork.c

SRCDIR = ./src/

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(CFLAGS) -o $(NAME) $(SRCS) -L libft/ -lft

all: $(NAME)

clean: 
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
