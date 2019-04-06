/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:36:28 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/06 14:35:50 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

inline static int	ft_len(unsigned long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		++i;
		n /= 10;
	}
	return (i);
}

char				*nzero(char *str)
{
	str[0] = '0';
	return (str);
}

char				*ft_itoa_ulong(unsigned long long n)
{
	unsigned long	nbr;
	int				i;
	char			*result;

	nbr = n;
	i = 0;
	if (!(result = ft_strnew((size_t)ft_len(nbr))))
			return (NULL);
	if (n == 0)
		return (nzero(result));
	while (nbr != 0)
	{
		result[ft_len(n) - i - 1] = (nbr % 10) + '0';
		nbr /= 10;
		++i;
	}
	return (result);
}
