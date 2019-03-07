# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:01:46 by lubenard          #+#    #+#              #
#    Updated: 2019/03/07 03:32:48 by lubenard         ###   ########.fr        #
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
	  srcs/lib/ft_isdigit.c \
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

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -c -Wall -Wextra -Werror -g3

all:  $(NAME)

$(NAME): $(OBJ)
	@printf "\033[33mCompilation de $(NAME)...\033[0m"
	@ar rc $(NAME) $(OBJ)
	@$(CC) -g3 -o ft_printf main.c libftprintf.a
	@printf "\033[32m[✓]\033[0m\n"

%.o : %.c
	@printf "\033[36mCompilation de $<...\033[0m"
	@$(CC) $(CFLAGS) $< -o $@
	@printf "\033[32m[✓]\033[0m\n"

clean:
	@printf "\033[31mFclean du projet...\033[0m"
	@rm -f $(OBJ)
	@printf "\033[32m[✓]\033[0m\n"

fclean: clean
	@printf "\033[31mFclean du projet...\033[0m"
	@rm -f $(NAME)
	@rm -rf ft_printf.dSYM
	@rm ft_printf
	@printf "\033[32m[✓]\033[0m\n"

re: fclean all
