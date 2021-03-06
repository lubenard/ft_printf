/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:38:58 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/17 15:28:40 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned int	negative_number(unsigned int nbr)
{
	if (nbr > UINT_MAX)
		return (UINT_MAX);
	return (nbr);
}

char			*get_option_u(va_list ap, t_word *lkd_list)
{
	if (ft_strstr(lkd_list->content, "ll") != 0)
		return (ft_itoa_ulong(va_arg(ap, unsigned long long)));
	else if (ft_strstr(lkd_list->content, "hh") != 0)
		return (ft_sstoa((unsigned char)va_arg(ap, int)));
	else if (ft_strchr(lkd_list->content, 'l') != -1)
		return (ft_itoa_ulong(va_arg(ap, unsigned long)));
	else if (ft_strchr(lkd_list->content, 'h') != -1)
		return (ft_stoa((short)va_arg(ap, int)));
	return (ft_itoa_ulong(negative_number(va_arg(ap, unsigned int))));
}

int				handle_ret_u(t_word *lkd_list, char *spaces, char *prec,
		char *to_remplace)
{
	if (spaces != NULL)
	{
		if (prec)
			free(prec);
		free(to_remplace);
		lkd_list->content = spaces;
	}
	else if (prec != NULL)
	{
		free(to_remplace);
		lkd_list->content = prec;
	}
	else
		lkd_list->content = to_remplace;
	return (0);
}

int				handle_errors_u(t_word *lkd_list, char *to_remplace)
{
	if (ft_strcmp(to_remplace, "0") == 0
	&& (ft_strstr(lkd_list->content, ".0")
	|| detect_prec(lkd_list->content, 0) == -1))
	{
		free(lkd_list->content);
		free(to_remplace);
		lkd_list->content = ft_strdup("");
		return (1);
	}
	return (0);
}

int				percent_u(t_word *lkd_list, va_list ap)
{
	int					i;
	char				*to_remplace;
	char				*spaces;
	char				*prec;

	i = 0;
	spaces = NULL;
	prec = NULL;
	to_remplace = get_option_u(ap, lkd_list);
	if (handle_errors_u(lkd_list, to_remplace) == 1)
		return (0);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		prec = precision(lkd_list->content, to_remplace, i, 0);
	if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
		&& prec != NULL)
		spaces = add_space(lkd_list, prec);
	else if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
		&& prec == NULL)
		spaces = add_space(lkd_list, to_remplace);
	free(lkd_list->content);
	return (handle_ret_u(lkd_list, spaces, prec, to_remplace));
}
