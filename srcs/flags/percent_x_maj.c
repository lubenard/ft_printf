/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_X_maj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:12:59 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/08 12:48:21 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		percent_x_maj(t_word *lkd_list, va_list ap)
{
	char	*to_remplace;
	int		j;

	j = 0;
	to_remplace = percent_x(lkd_list, ap, 1);
	while (to_remplace[j])
	{
		if (to_remplace[j] > 96 && to_remplace[j] < 123)
			to_remplace[j] -= 32;
		++j;
	}
	lkd_list->content = to_remplace;
	return (0);
}
