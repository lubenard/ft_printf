/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 00:11:51 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/27 23:34:18 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define MAX_INT64 (9223372036854775807LL)

#include <stdio.h>

typedef struct	s_parameter
{
	int		precision;
	int		flags;
	int		minimim_size;
}				t_parameter;

typedef struct	s_word
{
	void			*content;
	int				to_remplace;
	t_parameter		*parameter;
	struct s_word	*next;
}				t_word;

int				ft_printf(const char *str, ...);
void			ft_putstr(const char *str);
int				ft_strcchr(const char *str, const char *to_found);
char			*ft_itoa(int n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				parsing(char **str, va_list ap);
int				ft_strlen(const char *str);
void			remplacage(t_word *lkd_list, va_list ap);
void			ft_putchar(char c);
int				ft_atoi(const char *str);
/*
**Percentage conversion functions
*/
void			percent_c(t_word *lkd_list, va_list ap);
void			percent_s(t_word *lkd_list, va_list ap);
#endif
