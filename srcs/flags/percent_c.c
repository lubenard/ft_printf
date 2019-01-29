/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:57:06 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/29 17:24:38 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	return_pointer(int nbr)
{
	char c;

	c = nbr;
	return (c);
}

int		percent_c(t_word *lkd_list, va_list ap)
{
	char	to_remplace;
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char))))
		return (-1);
	to_remplace = return_pointer(va_arg(ap, int));
	tmp[0] = to_remplace;
	tmp[1] = '\0';
	lkd_list->content = tmp;
	return (0);
}
