/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 00:11:51 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/30 22:36:23 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define MAX_INT64 (9223372036854775807LL)

# include <stdio.h>

typedef struct	s_word
{
	char			*content;
	int				to_remplace;
	struct s_word	*next;
}				t_word;

int				ft_printf(const char *str, ...);
int				ft_strcchr(const char *str, const char *to_found);
int				parsing(char **str, va_list ap);
void			remplacage(t_word *lkd_list, va_list ap);
/*
** Libft functions
*/
void			ft_putstr(const char *str);
char			*ft_itoa(int n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strlen(const char *str);
void			ft_putchar(char c);
int				ft_atoi(const char *str);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_fill(char *str, char c, int length);
int				ft_strcmp(char const *s1, char const *s2);
/*
** Percentage conversion functions
*/
int				percent_c(t_word *lkd_list, va_list ap);
int				percent_s(t_word *lkd_list, va_list ap);
int				percent_x(t_word *lkd_list, va_list ap);
int				percent_percent(t_word *lkd_list);
/*
** Options functions
*/
char			*add_space(char *str, char *to_remplace);
#endif
