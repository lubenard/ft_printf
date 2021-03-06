/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 00:11:51 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/18 13:00:40 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define MAX_INT64 (9223372036854775807LL)
# include <limits.h>

typedef struct	s_word
{
	char			*content;
	short			is_malloc;
	long			manual_len;
	short			null_char;
	char			*spaces_char;
	int				spaces;
	struct s_word	*next;
	short			is_neg;
}				t_word;

typedef struct	s_percent_di
{
	char		*prec;
	char		*spaces;
	char		*tmp;
}				t_percent_di;
/*
** Printf functions
*/
int				ft_printf(const char *str, ...);
/*
** Useful functions
*/
int				ft_strcchr(const char *str, const char *to_found);
int				parsing(const char *str, va_list ap, int option);
int				remplacage(t_word *lkd_list, va_list ap);
char			*join_str(char *to_remplace, int length, int minus, char fill);
char			*rev(char *str);
char			*join_str_neg(char *to_remplace, int length);
char			*change_minus(char *str);
int				detect_prec(char *str, int mode);
char			*nzero(char *str);
char			*extract_number(char *str);
int				extract_prec(char *content, int j);
int				detect_zero(t_word *lkd_list);
/*
** Libft functions
*/
char			*ft_strstr(const char *str, const char *to_search);
char			*ft_itoa(int n);
char			*ft_itoa_long(long long int n);
char			*ft_itoa_ulong(unsigned long long n);
char			*ft_stoa(short n);
char			*ft_sstoa(short n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strlen(const char *str);
int				ft_atoi(const char *str);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_fill(char *str, char c, int length);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_strchr(char const *s, int c);
int				ft_putstr(int fd, t_word *lkd_list);
int				ft_isdigit(int c);
char			*ft_strdup(char const *s);
char			*ft_strnew(int n);
/*
** Convertions
*/
char			*convert_into_hexa(unsigned long value);
char			*conv_in_hexa_p(unsigned long value);
/*
** Percentage conversion functions
*/
int				percent_c(t_word *lkd_list, va_list ap);
int				percent_s(t_word *lkd_list, va_list ap);
char			*percent_x(t_word *lkd_list, va_list ap, short option);
int				percent_percent(t_word *lkd_list);
int				percent_di(t_word *lkd_list, va_list ap);
int				percent_p(t_word *lkd_list, va_list ap);
int				percent_o(t_word *lkd_list, va_list ap);
int				percent_x_maj(t_word *lkd_list, va_list ap);
int				percent_u(t_word *lkd_list, va_list ap);
/*
** Options functions
*/
char			*add_space(t_word *lkd_list, char *to_remplace);
char			*precision(char *content, char *to_remplace, int i, int mode);
int				brackets(t_word *lkd_list);
char			*add_zero_x(t_word *lkd_list, char *to_remplace,
		char *prec, char *spaces);
/*
** Useless Functions
** (Forced to move them to another fiile because of Norme)
*/
char			*return_x(t_word *lkd_list, char *zero_x, int option);
int				check_spaces(char *str);
t_percent_di	initialise_struct_di(void);
void			handle_ret_di2(t_percent_di *struct_di,
	t_word *lkd_list, char *to_remplace, int i);
int				check_null(char *prec, char *spaces, char *to_remplace);

#endif
