/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <lubenard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:38:17 by luca              #+#    #+#             */
/*   Updated: 2019/01/23 22:05:16 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		scanning(const char *str)
{
	int cnt;
	int i;
	int e;

	i = 0;
	cnt = 0;
	e = 0;
	while (str[i])
	{
		printf("Boucle char = %c, i = %d e = %d\n", str[i], i, e);
		if (str[i] == '%')
		{
			printf("Boucle = %s\n",ft_strsub(str, e, i));
			e = i;
		}
		i++;
	}
	//printf("Boucle = %s\n",ft_strsub(str, e, i));
	return (cnt);
}

int		ft_printf(const char *str, ...)
{
	va_list ap;

	va_start(ap, str); // stdarg pour avoir des arguments a l'infinie
	ft_putstr(ft_itoa(va_arg(ap, int))); //afficher un int par exemple
	printf("str=%d c=%c\n", ft_strcchr(str, "%lu"), str[ft_strcchr(str, "%lu")]);
	scanning(str);
	ft_putstr(str);
	return (0);
}
