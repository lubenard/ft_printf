/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:38:58 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/26 18:25:24 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned long long		get_option_u(va_list ap, int option)
{
	if (option == 1)
		return(va_arg(ap, unsigned long));
	else if (option == 2)
		return(va_arg(ap, unsigned long long));
	else if (option == 3)
		return((short)va_arg(ap, int));
	else if (option == 4)
		return((char)va_arg(ap, int));
	return (0);
}

unsigned int		negative_number(unsigned int nbr)
{
	if (nbr < 0)
		return(UINT_MAX - nbr);
	else if (nbr > UINT_MAX)
		return(UINT_MAX);
	return(nbr);
}

int		percent_u(t_word *lkd_list, va_list ap)
{
	unsigned long long		value;
	int						i;
	char					*to_remplace;

	i = 0;
	if (ft_strchr(lkd_list->content, 'l') != -1)
		value = get_option_u(ap, 1);
	else if (ft_strstr(lkd_list->content, "ll") != 0)
		value = get_option_u(ap, 2);
	else if (ft_strchr(lkd_list->content, 'h') != -1)
		value = get_option_u(ap, 3);
	else if (ft_strstr(lkd_list->content, "hh") != 0)
		value = get_option_u(ap, 4);
	else
		value = negative_number(va_arg(ap, unsigned int));
	to_remplace = ft_itoa_long(value);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		to_remplace = precision(lkd_list->content, to_remplace, i, 0);
	if (lkd_list->content[1] != 'u')
	{
		if ((to_remplace = add_space(lkd_list->content, to_remplace)) == NULL)
			return (-1);
	}
	lkd_list->content = to_remplace;
	return (0);
}
