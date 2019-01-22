/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 00:25:11 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/22 21:56:59 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_strcchr(const char *str, const char *to_found)
{
	int i;
	int e;

	e = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == to_found[e])
			e++;
		if (to_found[e] == '\0')
			return (i - e + 1);
		i++;
	}
	return (-1);
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}
