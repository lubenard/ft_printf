/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:41:36 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/31 22:50:56 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		percent_s(t_word *lkd_list, va_list ap)
{
	char	*to_remplace;
	int		i;

	i = 0;
	to_remplace = va_arg(ap, char *);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		to_remplace = precision(lkd_list->content, to_remplace, i);
	if (lkd_list->content[1] != 's')
	{
		if ((to_remplace = add_space(lkd_list->content, to_remplace)) == NULL)
			return (-1);
	}
	lkd_list->content = to_remplace;
	return (0);
}
