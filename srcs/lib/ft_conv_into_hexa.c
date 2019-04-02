/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_into_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:39:56 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/02 19:44:15 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*conv_in_hexa_p(unsigned long value)
{
	char	*ret;
	int		i;
	int		tmp;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * 19)))
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
	ret[i] = 'x';
	ret[++i] = '0';
	return (rev(ret));
}

char	*convert_into_hexa(unsigned long value)
{
	char			*ret;
	int				i;
	long long		tmp;

	i = 0;
	if (!(ret = ft_strnew(17)))
		return (NULL);
	if (value == 0)
	{
		ret[0] = '0';
		return (ret);
	}
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
	return (rev(ret));
}
