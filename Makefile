# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:01:46 by lubenard          #+#    #+#              #
#    Updated: 2019/04/04 19:05:00 by lubenard         ###   ########.fr        #
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
	  srcs/lib/ft_itoa_ulong.c \
	  srcs/lib/ft_strdup.c \
	  srcs/lib/ft_conv_into_hexa.c \
	  srcs/lib/ft_stoa.c \
	  srcs/lib/ft_strnew.c \
	  srcs/flags/percent_c.c \
	  srcs/flags/percent_s.c \
	  srcs/flags/percent_x.c \
	  srcs/flags/percent_di.c\
	  srcs/flags/percent_p.c \
	  srcs/flags/percent_o.c \
	  srcs/flags/percent_u.c \
	  srcs/flags/percent_x_maj.c \
	  srcs/flags/add_space.c \
	  srcs/flags/precision.c \
	  srcs/flags/add_zero_x.c

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -g3 -c -Wall -Wextra -Werror

all:  $(NAME)

$(NAME): $(OBJ)
	@printf "\033[33mCompilation de $(NAME)...\033[0m"
	@ar rc $(NAME) $(OBJ)
	@$(CC) -g3 -o ft_printf main2.c libftprintf.a
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
	@rm -f ft_printf
	@printf "\033[32m[✓]\033[0m\n"

re: fclean all
