/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:01:46 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/01 16:07:58 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** How to convert pointer address into %p ?
** Convert it in long unsigned int, then convert it in hexa
** Then add 0x before
** https://repl.it/repls/ValidBestFlashdrives
*/

char	*conv_in_hexa_ul(unsigned long value)
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
	return (rev(ret));
}

int		percent_p(t_word *lkd_list, va_list ap)
{
	char				*to_remplace2;
	char				*to_remplace;
	unsigned long		value;
	int					i;

	to_remplace2 = NULL;
	value = va_arg(ap, unsigned long);
	if (value == 0)
	{
		lkd_list->content = "(nil)";
		lkd_list->is_malloc = 0;
		return (0);
	}
	to_remplace = conv_in_hexa_ul(value);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		to_remplace = precision(lkd_list->content, to_remplace, i, 0);
	to_remplace = ft_strjoin("0x", to_remplace);
	if (lkd_list->content[1] != 'p')
		to_remplace2 = add_space(lkd_list->content, to_remplace);
	free(lkd_list->content);
	lkd_list->content = to_remplace2;
	free(to_remplace);
	return (0);
}
