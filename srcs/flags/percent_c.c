/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:57:06 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/06 21:38:29 by lubenard         ###   ########.fr       */
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
	char	get_value;
	char	*to_remplace;
	char	*tmp;

	get_value = return_pointer(va_arg(ap, int));
	if (!(to_remplace = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	to_remplace[0] = get_value;
	to_remplace[1] = '\0';
	if (lkd_list->content[1] != 'c')
	{
		tmp = to_remplace;
		free(to_remplace);
		lkd_list->is_malloc = 1;
		to_remplace = add_space(lkd_list->content, tmp);
	}
	free(lkd_list->content);
	lkd_list->content = to_remplace;
	return (0);
}

int		percent_percent(t_word *lkd_list)
{
	char *to_remplace;

	if (!(to_remplace = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	to_remplace[0] = '%';
	to_remplace[1] = '\0';
	free(lkd_list->content);
	lkd_list->content = to_remplace;
	return (0);
}
