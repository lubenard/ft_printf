/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:38:58 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/07 04:19:18 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned int		negative_number(unsigned int nbr)
{
	if (nbr > UINT_MAX)
		return (UINT_MAX);
	return (nbr);
}

unsigned long long	get_option_u(va_list ap, t_word *lkd_list)
{
	if (ft_strchr(lkd_list->content, 'l') != -1)
		return (va_arg(ap, unsigned long));
	else if (ft_strstr(lkd_list->content, "ll") != 0)
		return (va_arg(ap, unsigned long long));
	else if (ft_strchr(lkd_list->content, 'h') != -1)
		return ((short)va_arg(ap, int));
	else if (ft_strstr(lkd_list->content, "hh") != 0)
		return ((char)va_arg(ap, int));
	return (negative_number(va_arg(ap, unsigned int)));
}

int					handle_ret_u(t_word *lkd_list, char *spaces,
		char *prec, char *to_remplace)
{
	if (spaces != NULL)
	{
		if (prec != NULL)
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

int					percent_u(t_word *lkd_list, va_list ap)
{
	unsigned long long	value;
	int					i;
	char				*to_remplace;
	char				*prec;
	char				*spaces;

	i = 0;
	prec = NULL;
	spaces = NULL;
	value = get_option_u(ap, lkd_list);
	to_remplace = ft_itoa_long(value);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		prec = precision(lkd_list->content, to_remplace, i, 0);
	if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
			&& prec == NULL)
		spaces = add_space(lkd_list->content, to_remplace);
	else if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
			&& prec != NULL)
		spaces = add_space(lkd_list->content, prec);
	free(lkd_list->content);
	return (handle_ret_u(lkd_list, spaces, prec, to_remplace));
}
