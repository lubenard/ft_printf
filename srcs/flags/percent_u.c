/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:38:58 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/06 17:29:17 by lubenard         ###   ########.fr       */
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
		return (ft_itoa_ulong((unsigned char)va_arg(ap, int)));
	else if (ft_strchr(lkd_list->content, 'l') != -1)
		return (ft_itoa_ulong(va_arg(ap, unsigned long)));
	else if (ft_strchr(lkd_list->content, 'h') != -1)
		return (ft_itoa_ulong((short)va_arg(ap, int)));
	return (ft_itoa_ulong(negative_number(va_arg(ap, unsigned int))));
}

int				handle_ret_u(t_word *lkd_list, char *spaces,
		char *to_remplace)
{
	if (spaces != NULL)
	{
		free(to_remplace);
		lkd_list->content = spaces;
	}
	else
		lkd_list->content = to_remplace;
	return (0);
}

int				percent_u(t_word *lkd_list, va_list ap)
{
	int					i;
	char				*to_remplace;
	char				*spaces;
	char				*tmp;

	i = 0;
	spaces = NULL;
	to_remplace = get_option_u(ap, lkd_list);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
	{
		tmp = to_remplace;
		free(to_remplace);
		to_remplace = precision(lkd_list->content, tmp, i, 0);
	}
	if (ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
		spaces = add_space(lkd_list->content, to_remplace);
	free(lkd_list->content);
	return (handle_ret_u(lkd_list, spaces, to_remplace));
}
