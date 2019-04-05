/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 00:25:11 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/05 12:00:53 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*rev(char *str)
{
	char	*rev_str;
	int		j;
	int		len;

	len = ft_strlen(str);
	if (!(rev_str = ft_strnew(len)))
		return (NULL);
	j = 0;
	--len;
	while (len >= 0)
	{
		rev_str[j] = str[len];
		j++;
		--len;
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
		++i;
	return (i);
}

int		ft_putstr(int fd, t_word *lkd_list)
{
	int		len;

	len = ft_strlen(lkd_list->content);
	write(fd, lkd_list->content, len);
	if (lkd_list->manual_len != -1)
		return (lkd_list->manual_len);
	return (len);
}
