/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:23:03 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/04 15:43:43 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

char	*convert_into_hexa(int value)
{
	char	*ret;
	int		i;
	int		tmp;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * 10)))
		return (NULL);
	while (value != 0)
	{
		tmp = 0;
		tmp = value % 16;
		if (tmp < 10)
			ret[i] = tmp + 48;
		else
			ret[i] = tmp + 87;
		++i;
		value = value / 16;
	}
	return (ret);
}

int		percent_x(t_word *lkd_list, va_list ap)
{
	char	*to_remplace;
	int		get_value;
	int		i;

	i = 0;
	get_value = va_arg(ap, int);
	to_remplace = convert_into_hexa(get_value);
	to_remplace = rev(to_remplace);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		to_remplace = precision(lkd_list->content, to_remplace, i, 0);
	if (lkd_list->content[1] != 'x')
		to_remplace = add_space(lkd_list->content, to_remplace);
	lkd_list->content = to_remplace;
	return (0);
}
