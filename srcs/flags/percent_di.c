/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:01:12 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/22 17:10:02 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		get_option(va_list ap, int option)
{
	int		get_value;

	get_value = 0;
	if (option == 1)
		get_value = va_arg(ap, long int);
	else if (option == 2)
		get_value = va_arg(ap, long long int);
	else if (option == 3)
		get_value = (short)va_arg(ap, int);
	else if (option == 4)
		get_value = (char)va_arg(ap, int);
	return (get_value);
}

int		percent_di(t_word *lkd_list, va_list ap)
{
	char	*to_remplace;
	int		get_value;
	int		i;

	i = 0;
	if (ft_strchr(lkd_list->content, 'l') != -1)
		get_value = get_option(ap, 1);
	else if (ft_strstr(lkd_list->content, "ll") != 0)
		get_value = get_option(ap, 2);
	else if (ft_strchr(lkd_list->content, 'h') != -1)
		get_value = get_option(ap, 3);
	else if (ft_strstr(lkd_list->content, "hh") != 0)
		get_value = get_option(ap, 4);
	else
		get_value = va_arg(ap, int);
	to_remplace = ft_itoa(get_value);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		to_remplace = precision(lkd_list->content, to_remplace, i, 0);
	if (lkd_list->content[1] != 'd')
		to_remplace = add_space(lkd_list->content, to_remplace);
	lkd_list->content = to_remplace;
	return (0);
}
