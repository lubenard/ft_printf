/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <lubenard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:38:17 by luca              #+#    #+#             */
/*   Updated: 2019/01/26 14:31:58 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		scanning(const char *str)
{
	int i;
	int e;
	int k;

	k = 0;
	e = 0;
	i = 0;
	while (str[i])
	{
		printf("char traite = %c , i = %d, e = %d, k = %d\n", str[i], i, e, k);
		if (str[i] == '%')
		{
			printf("Detection = %s\n", ft_strsub(str, k, e));
			k = i;
			e = 0;
		}
		++i;
		++e;
	}
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	char	*tab[] = {"test", "%d", "Ptdr", "%c","\0"};

	va_start(ap, str); // stdarg pour avoir des arguments a l'infinie
	//ft_putstr(ft_itoa(va_arg(ap, int))); //afficher un int par exemple
	parsing(tab, ap);
	//scanning(str);
	return (0);
}
