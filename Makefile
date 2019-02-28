# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:01:46 by lubenard          #+#    #+#              #
#    Updated: 2019/02/28 18:57:42 by lubenard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = srcs/ft_printf.c \
	  srcs/utils.c \
	  srcs/parsing.c \
	  srcs/rempl.c \
	  srcs/lib/ft_itoa.c \
	  srcs/lib/ft_itoa_long.c \
	  srcs/lib/ft_atoi.c \
	  srcs/lib/ft_strsub.c \
	  srcs/lib/ft_strjoin.c \
	  srcs/lib/ft_fill.c \
	  srcs/lib/ft_strcmp.c \
	  srcs/lib/ft_strchr.c \
	  srcs/lib/ft_strstr.c \
	  srcs/flags/percent_c.c \
	  srcs/flags/percent_s.c \
	  srcs/flags/percent_x.c \
	  srcs/flags/percent_di.c\
	  srcs/flags/percent_p.c \
	  srcs/flags/percent_o.c \
	  srcs/flags/percent_u.c \
	  srcs/flags/add_space.c \
	  srcs/flags/precision.c \
	  srcs/flags/brackets.c \
	  main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all:  $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@gcc -o ft_printf main.c libftprintf.a
	@echo -e "ft_printf \033[32mDONE !\033[0m"

%.o : %.c
	@clang -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@echo -e "clean ft_printf \033[32mDONE !\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -rf ft_printf.dSYM
	@rm ft_printf
	@echo -e "fclean ft_printf \033[32mDONE !\033[0m"

re: fclean all
