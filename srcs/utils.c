/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 00:25:11 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/23 08:33:37 by lubenard         ###   ########.fr       */
/*                                                                            */

/* ************************************************************************** */

#include "ft_printf.h"

char	*rev(char *str)
{
	char	*rev_str;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(str);
	if (!(rev_str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	j = 0;
	i = ft_strlen(str);
	i--;
	while (i >= 0)
	{
		rev_str[j] = str[i];
		j++;
		i--;
	}
	free(str);
	return (rev_str);
}

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

int		ft_putstr(int fd, char *str)
{
	int		len;

	len = ft_strlen(str);
	write(fd, str, len);
	return (len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
