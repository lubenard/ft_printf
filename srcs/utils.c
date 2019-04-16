/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 00:25:11 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/16 18:03:53 by lubenard         ###   ########.fr       */
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
	int		i;

	i = 0;
	len = ft_strlen(lkd_list->content);
	if (lkd_list->null_char == 1)
	{
		while (i < lkd_list->manual_len)
			write(1, &lkd_list->content[i++], 1);
	}
	else
		write(fd, lkd_list->content, len);
	if (lkd_list->manual_len != -1)
		return (lkd_list->manual_len);
	return (len);
}

int		extract_prec(char *content, int i)
{
	char	*sub;
	int		length;
	int		k;
	int		j;

	if (i == -1)
		i = ft_strchr(content, '.');
	j = i + 1;
	i++;
	k = i;
	while (content[i] > 47 && content[i] < 58)
		++i;
	sub = ft_strsub(content, j, i - k);
	length = ft_atoi(sub);
	free(sub);
	return (length);
}

char	*change_minus(char *str)
{
	int		i;
	char	tmp;
	int		e;

	i = 0;
	e = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && i > 0)
		{
			while (str[e] == ' ')
				e++;
			tmp = str[e];
			str[e] = (str[i] == '-') ? '-' : '+';
			str[i] = tmp;
		}
		++i;
	}
	return (str);
}
