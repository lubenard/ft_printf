/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rempl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <lubenard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 23:33:55 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/10 18:17:26 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		remplacage(t_word *lkd_list, va_list ap)
{
	if (lkd_list->content[ft_strlen(lkd_list->content) - 1] == 's')
		percent_s(lkd_list, ap);
	else if (lkd_list->content[ft_strlen(lkd_list->content) - 1] == 'c')
		percent_c(lkd_list, ap);
	else if (lkd_list->content[ft_strlen(lkd_list->content) - 1] == 'x')
		percent_x(lkd_list, ap, 0);
	else if (lkd_list->content[ft_strlen(lkd_list->content) - 1] == 'X')
		percent_x_maj(lkd_list, ap);
	else if (lkd_list->content[ft_strlen(lkd_list->content) - 1] == '%')
		percent_percent(lkd_list);
	else if (lkd_list->content[ft_strlen(lkd_list->content) - 1] == 'p')
		percent_p(lkd_list, ap);
	else if (lkd_list->content[ft_strlen(lkd_list->content) - 1] == 'd'
	|| lkd_list->content[ft_strlen(lkd_list->content) - 1] == 'i'
	|| lkd_list->content[ft_strlen(lkd_list->content) - 1] == 'f')
		percent_di(lkd_list, ap);
	else if (lkd_list->content[ft_strlen(lkd_list->content) - 1] == 'o')
		percent_o(lkd_list, ap);
	else if (lkd_list->content[ft_strlen(lkd_list->content) - 1] == 'u')
		percent_u(lkd_list, ap);
	return (0);
}
