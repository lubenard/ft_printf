/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 00:11:51 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/01 00:16:47 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define MAX_INT64 (9223372036854775807LL)
# include <limits.h>


#include <stdio.h>

typedef struct	s_word
{
	char			*content;
	struct s_word	*next;
	short			is_malloc;
}				t_word;
/*
** Printf functions
*/
int				ft_printf(const char *str, ...);
int				ft_dprintf(int fd, const char *str, ...);
/*
** Useful functions
*/
int				ft_strcchr(const char *str, const char *to_found);
int				parsing(const char *str, va_list ap, int option);
int				remplacage(t_word *lkd_list, va_list ap);
char			*join_str(char *to_remplace, int length, int minus, char fill);
char			*rev(char *str);
/*
** Libft functions
*/
char			*ft_strstr(const char *str, const char *to_search);
char			*ft_itoa(int n);
char			*ft_itoa_long(long long int n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strlen(const char *str);
int				ft_atoi(const char *str);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_fill(char *str, char c, int length);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_strchr(char const *s, int c);
int				ft_putstr(int fd, char *str);
/*
** Percentage conversion functions
*/
int				percent_c(t_word *lkd_list, va_list ap);
int				percent_s(t_word *lkd_list, va_list ap);
int				percent_x(t_word *lkd_list, va_list ap);
int				percent_percent(t_word *lkd_list);
int				percent_di(t_word *lkd_list, va_list ap);
int				percent_p(t_word *lkd_list, va_list ap);
int				percent_o(t_word *lkd_list, va_list ap);
int				percent_x_maj(t_word *lkd_list, va_list ap);
int				percent_u(t_word *lkd_list, va_list ap);
/*
** Options functions
*/
char			*add_space(char *content, char *to_remplace);
char			*precision(char *content, char *to_remplace, int i, int mode);
int				brackets(t_word *lkd_list);
#endif
