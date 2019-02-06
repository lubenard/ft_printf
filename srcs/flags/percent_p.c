/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:01:46 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/06 12:05:04 by lubenard         ###   ########.fr       */
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
	void				*get_value;
	char				*to_remplace;
	unsigned long		value;

	get_value = va_arg(ap, void *);
	value = (unsigned long)get_value;
	to_remplace = ft_strjoin("0x", conv_in_hexa_ul(value));
	if (lkd_list->content[1] != 'p')
		to_remplace = add_space(lkd_list->content, to_remplace);
	lkd_list->content = to_remplace;
	return (0);
}
