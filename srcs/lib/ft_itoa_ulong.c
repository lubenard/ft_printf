/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:36:28 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/11 17:13:01 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

inline static int		ft_len(int long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		++i;
		n /= 10;
	}
	return (i);
}

inline static char*		nzero(char *str)
{
	str[0] = '0';
	return (str);
}

char						*ft_itoa_ulong(unsigned long long n)
{
	long int nbr;
	int neg;
	int i;
	char* result;

	nbr = n;
	i = 0;
	neg = (nbr < 0) ? 1 : 0;
	result = ft_strnew((size_t)ft_len(nbr) + neg);
	if (nbr < 0)
	{
		i = -1;
		nbr = -nbr;
		result[0] = '-';
		++i;
	}
	if (n == 0)
		return (nzero(result));
	while (nbr != 0)
	{
		result[ft_len(n) - i + neg - 1] = (nbr % 10) + '0';
		nbr /= 10;
		++i;
	}
	return (result);
}
