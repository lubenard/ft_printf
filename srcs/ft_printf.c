/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <lubenard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:38:17 by luca              #+#    #+#             */
/*   Updated: 2019/01/23 18:47:24 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		scanning(const char *str)
{
	int cnt;
	int i;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		i++;
	}
	return (cnt);
}

int		ft_printf(const char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	ft_putstr(ft_itoa(va_arg(ap, int)));
	printf("str=%d c=%c\n", ft_strcchr(str, "%lu"), str[ft_strcchr(str, "%lu")]);
	if (ft_strcchr(str, "%d") == -1)
		ft_putstr(str);
	return (0);
}
