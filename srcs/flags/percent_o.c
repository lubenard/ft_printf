/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:43:35 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/23 08:44:11 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned int 		get_option_o(va_list ap, int option)
{
	unsigned int		get_value;

	get_value = 0;
	if (option == 1)
		get_value = va_arg(ap, long int);
	else if (option == 2)
		get_value = va_arg(ap, long long int);
	else if (option == 3)
		get_value = (short)va_arg(ap, int);
	else if (option == 4)
		get_value = (char)va_arg(ap, int);
	return (get_value);
}

char	*convert_in_octal(int value)
{
	int		i;
	int		octal_num;

	octal_num = 0;
	i = 1;
	while (value != 0)
	{
		octal_num += (value % 8) * i;
		value /= 8;
		i *= 10;
	}
	return (ft_itoa(octal_num));
}

int		percent_o(t_word *lkd_list, va_list ap)
{
	unsigned int	value;

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
