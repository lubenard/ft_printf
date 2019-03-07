/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:47:17 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/07 12:50:04 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_bzero(void *s, int n)
{
	int		i;
	char	*t;

	i = 0;
	t = (char *)s;
	while (i != (int)n)
		t[i++] = '\0';
}

char	*ft_strnew(int n)
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	ft_bzero(dest, sizeof(char) * n + 1);
	return (dest);
}
