/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:57:06 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/11 15:01:55 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		percent_c(t_word *lkd_list, va_list ap)
{
	char	*to_remplace;
	char	*tmp;

	tmp = NULL;
	if (!(to_remplace = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	to_remplace[0] = va_arg(ap, int);
	to_remplace[1] = '\0';
	if (ft_isdigit(lkd_list->content[1])
		|| lkd_list->content[1] == '-')
	{
		tmp = ft_strdup(to_remplace);
		free(to_remplace);
		to_remplace = add_space(lkd_list->content, tmp);
		free(tmp);
	}
	free(lkd_list->content);
	lkd_list->content = to_remplace;
	return (0);
}

int		percent_percent(t_word *lkd_list)
{
	char	*to_remplace;
	char	*tmp;

	tmp = NULL;
	if (!(to_remplace = (char *)malloc(sizeof(char) * 2)))
	return (-1);
	to_remplace[0] = '%';
	to_remplace[1] = '\0';
	if (ft_isdigit(lkd_list->content[1])
		|| lkd_list->content[1] == '-')
	{
		tmp = ft_strdup(to_remplace);
		free(to_remplace);
		to_remplace = add_space(lkd_list->content, tmp);
		free(tmp);
	}
	free(lkd_list->content);
	lkd_list->content = to_remplace;
	return (0);
}
