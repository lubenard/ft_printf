/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:43:35 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/26 17:57:17 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned long long		get_option_o(va_list ap, int option)
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

char	*convert_in_octal(unsigned long long value)
{
	unsigned long long		i;
	unsigned long long		octal_num;

	octal_num = 0;
	i = 1;
	while (value != 0)
	{
		octal_num += (value % 8) * i;
		value /= 8;
		i *= 10;
	}
	return (ft_itoa_long(octal_num));
}

int		percent_o(t_word *lkd_list, va_list ap)
{
	unsigned long long	value;

	if (ft_strchr(lkd_list->content, 'l') != -1)
		value = get_option_o(ap, 1);
	else if (ft_strstr(lkd_list->content, "ll") != 0)
		value = get_option_o(ap, 2);
	else if (ft_strchr(lkd_list->content, 'h') != -1)
		value = get_option_o(ap, 3);
	else if (ft_strstr(lkd_list->content, "hh") != 0)
		value = get_option_o(ap, 4);
	else
		value = va_arg(ap, unsigned int);
	lkd_list->content = convert_in_octal(value);
	return (0);
}
