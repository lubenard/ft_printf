# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:01:46 by lubenard          #+#    #+#              #
#    Updated: 2019/01/23 18:44:36 by lubenard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = srcs/ft_printf.c \
	  srcs/utils.c \
	  srcs/lib/ft_itoa.c \
	  srcs/main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all:  $(NAME)

$(NAME): $(OBJ)
	@clang -o $(NAME) $(CFLAGS) $(OBJ) -Isrcs/includes/
	@echo "ft_printf \033[32mDONE !\033[0m"

%.o : %.c
	@clang -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "clean ft_printf \033[32mDONE !\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -rf fillit.dSYM
	@echo "fclean ft_printf \033[32mDONE !\033[0m"

re: fclean all
