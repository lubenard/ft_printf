/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:38:58 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/08 18:13:38 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		percent_u(t_word *lkd_list, va_list ap)
{
	void		*get_value;
	unsigned	value;
	int			i;
	char		*to_remplace;

	i = 0;
	get_value = va_arg(ap, void *);
	value = (unsigned)get_value;
	to_remplace = ft_itoa(value);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		to_remplace = precision(lkd_list->content, to_remplace, i, 0);
	if (lkd_list->content[1] != 'u')
	{
		if ((to_remplace = add_space(lkd_list->content, to_remplace)) == NULL)
			return (-1);
	}
	lkd_list->content = to_remplace;
	return (0);
}
