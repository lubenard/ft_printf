/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:01:12 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/07 16:40:31 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "percent_di.h"

char		*get_option_d(va_list ap, t_word *lkd_list)
{
	if (ft_strstr(lkd_list->content, "ll") != NULL)
		return (ft_itoa_long(va_arg(ap, long long int)));
	else if (ft_strstr(lkd_list->content, "hh") != NULL)
		return (ft_stoa((short)va_arg(ap, int)));
	else if (ft_strchr(lkd_list->content, 'l') != -1)
		return (ft_itoa_long(va_arg(ap, long int)));
	else if (ft_strchr(lkd_list->content, 'h') != -1)
		return (ft_itoa(va_arg(ap, int)));
	else
		return (ft_itoa(va_arg(ap, int)));
}

int			handle_ret_di(t_percent_di struct_di, t_word *lkd_list,
		char *to_remplace)
{
	free(lkd_list->content);
	if (struct_di.tmp != NULL)
	{
		if (struct_di.spaces != NULL)
			free(struct_di.spaces);
		free(to_remplace);
		lkd_list->content = struct_di.tmp;
	}
	else if (struct_di.spaces != NULL)
	{
		if (struct_di.prec != NULL)
			free(struct_di.prec);
		free(to_remplace);
		lkd_list->content = struct_di.spaces;
	}
	else if (struct_di.prec != NULL)
	{
		free(to_remplace);
		lkd_list->content = struct_di.prec;
	}
	else
		lkd_list->content = to_remplace;
	return (0);
}

int			percent_di(t_word *lkd_list, va_list ap)
{
	char			*to_remplace;
	int				i;
	t_percent_di	struct_di;

	i = 0;
	struct_di.spaces = NULL;
	struct_di.prec = NULL;
	struct_di.tmp = NULL;
	to_remplace = get_option_d(ap, lkd_list);
	if (ft_strchr(lkd_list->content, ' ') != -1 && to_remplace[0] != '-')
		struct_di.tmp = ft_strjoin(" ", to_remplace);
	else if (ft_strchr(lkd_list->content, '+') != -1 && to_remplace[0] != '-')
		struct_di.tmp = ft_strjoin("+", to_remplace);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		struct_di.prec = precision(lkd_list->content, to_remplace, i, 0);
	else if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		struct_di.prec = precision(lkd_list->content, struct_di.tmp, i, 0);
	if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
		&& struct_di.prec == NULL)
		struct_di.spaces = add_space(lkd_list->content, to_remplace);
	else if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
		&& struct_di.prec != NULL)
		struct_di.spaces = add_space(lkd_list->content, struct_di.prec);
	return (handle_ret_di(struct_di, lkd_list, to_remplace));
}
