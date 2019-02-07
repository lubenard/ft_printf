/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:43:35 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/07 11:00:07 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	void			*get_value;
	unsigned int	value;

	get_value = va_arg(ap, void *);
	value = (unsigned int)get_value;
	(void)lkd_list;
	lkd_list->content = convert_in_octal(value);
	return (0);
}