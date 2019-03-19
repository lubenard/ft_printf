/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:36:28 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/19 18:28:28 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

inline static int		ft_len(long n)
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

inline static char*		nzero_long_long(char *str)
{
	str[0] = '0';
	return (str);
}

long long					correct_values_long(long long n)
{
	unsigned long long p;

	p = 0;
	if (n > LLONG_MAX)
		return(LLONG_MIN + (n - (LLONG_MIN * -1)));
	else if (n < LLONG_MAX - 1)
		return (LLONG_MAX -((n * -1) - LLONG_MAX - 2));
	return (n);
}

char						*ft_itoa_long(long long n)
{
	long int nbr;
	int neg;
	int i;
	char* result;

	n = correct_values_long(n);
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
		return (nzero_long_long(result));
	while (nbr != 0)
	{
		result[ft_len(n) - i + neg - 1] = (nbr % 10) + '0';
		nbr /= 10;
		++i;
	}
	return (result);
}
