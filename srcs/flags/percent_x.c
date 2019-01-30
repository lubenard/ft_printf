/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:23:03 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/30 15:47:05 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*convert_into_hexa(int value)
{
	char	*ret;
	int		i;
	int		tmp;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * 10)))
		return (NULL);
	while (value != 0)
	{
		tmp = 0;
		tmp = value % 16;
		if (tmp < 10)
			ret[i] = tmp + 48;
		else
			ret[i] = tmp + 87;
		++i;
		value = value / 16;
	}
	return (ret);
}

int		percent_x(t_word *lkd_list, va_list ap)
{
	char	*to_remplace;
	int		get_value;

	get_value = va_arg(ap, int);
	to_remplace = convert_into_hexa(get_value);
	lkd_list->content = to_remplace;
	return (0);
}
