/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:57:06 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/16 14:31:59 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#include <stdio.h>

int		percent_c(t_word *lkd_list, va_list ap)
{
	char	*to_remplace;
	char	*tmp;

	tmp = NULL;
	if ((to_remplace = ft_strnew(2)) == NULL)
		return (0);
	to_remplace[0] = va_arg(ap, int);
	to_remplace[1] = '\0';
	if (to_remplace[0] == 0)
		lkd_list->null_char = 1;
	if (lkd_list->spaces > 0 || lkd_list->content[1] == '-')
	{
		tmp = ft_strdup(to_remplace);
		free(to_remplace);
		to_remplace = add_space(lkd_list, tmp);
		free(tmp);
	}
	free(lkd_list->content);
	lkd_list->content = to_remplace;
	if (lkd_list->null_char)
		lkd_list->manual_len = ft_strlen(to_remplace) + 1;
	return (0);
}

int		percent_percent(t_word *lkd_list)
{
	char	*to_remplace;
	char	*tmp;

	tmp = NULL;
	if ((to_remplace = ft_strnew(2)) == NULL)
		return (0);
	to_remplace[0] = '%';
	to_remplace[1] = '\0';
	if (lkd_list->spaces > 0 || lkd_list->content[1] == '-')
	{
		tmp = ft_strdup(to_remplace);
		free(to_remplace);
		to_remplace = add_space(lkd_list, tmp);
		free(tmp);
	}
	free(lkd_list->content);
	lkd_list->content = to_remplace;
	return (0);
}
