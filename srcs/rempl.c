/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rempl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <lubenard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 23:33:55 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/29 17:51:30 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	remplacage(t_word *lkd_list, va_list ap)
{
	t_word	*save_lkd;

	save_lkd = lkd_list;
	while (lkd_list)
	{
		if (lkd_list->to_remplace == 1)
		{
			if (lkd_list->content[ft_strlen(lkd_list->content) - 1] == 's')
				percent_s(lkd_list, ap);
			if (lkd_list->content[ft_strlen(lkd_list->content) - 1] == 'c')
				percent_c(lkd_list, ap);
//			if (lkd_list->content[ft_strlen(lkd_list->content) - 1] == 'p')
//				percent_p(lkd_list, ap);
		}
		lkd_list = lkd_list->next;
	}
}
