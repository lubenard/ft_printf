/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:36:28 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/19 16:48:11 by lubenard         ###   ########.fr       */
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

inline static char*		nzero_short(char *str)
{
	str[0] = '0';
	return (str);
}

char						*ft_stoa(short n)
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
		return (nzero_short(result));
	while (nbr != 0)
	{
		result[ft_len(n) - i + neg - 1] = (nbr % 10) + '0';
		nbr /= 10;
		++i;
	}
	return (result);
}

int							correct_values(short n)
{
	if (n > 127)
		return (SCHAR_MIN + (n - (SCHAR_MIN * -1)));
	else if (n < -128)
		return (SCHAR_MAX - ((n * -1) - SCHAR_MAX - 2));
	return(n);
}

char						*ft_sstoa(short n)
{
	long int nbr;
	int neg;
	int i;
	char* result;

	n  = correct_values(n);
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
		return (nzero_short(result));
	while (nbr != 0)
	{
		result[ft_len(n) - i + neg - 1] = (nbr % 10) + '0';
		nbr /= 10;
		++i;
	}
	return (result);
}
