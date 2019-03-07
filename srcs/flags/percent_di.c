/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:01:12 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/07 03:37:23 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long long		get_option_d(va_list ap, int option)
{

	if (option == 1)
		return(va_arg(ap, long long int));
	else if (option == 2)
		return(va_arg(ap, int));
	else if (option == 3)
		return(va_arg(ap, long int));
	else if (option == 4)
		return(va_arg(ap, int));
	return(0);
}

int		percent_di(t_word *lkd_list, va_list ap)
{
	char		*to_remplace;
	int			i;
	char		*prec;
	char		*spaces;
	char		*tmp;

	spaces = NULL;
	prec = NULL;
	i = 0;
	tmp = NULL;
	if (ft_strstr(lkd_list->content, "ll") != NULL)
		to_remplace = ft_itoa_long(get_option_d(ap, 1));
	else if (ft_strstr(lkd_list->content, "hh") != NULL)
		to_remplace = ft_itoa((int)get_option_d(ap, 2));
	else if (ft_strchr(lkd_list->content, 'l') != -1)
		to_remplace = ft_itoa_long((long int)get_option_d(ap, 3));
	else if (ft_strchr(lkd_list->content, 'h') != -1)
		to_remplace = ft_itoa((short)get_option_d(ap, 4));
	else
		to_remplace = ft_itoa(va_arg(ap, int));
	if (ft_strchr(lkd_list->content, ' ') != -1 && to_remplace[0] != '-')
		tmp = ft_strjoin(" ", to_remplace);
	else if (ft_strchr(lkd_list->content, '+') != -1 && to_remplace[0] != '-')
		tmp = ft_strjoin("+", to_remplace);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		prec = precision(lkd_list->content, to_remplace, i, 0);
	else if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		prec = precision(lkd_list->content, tmp, i, 0);
	if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-') && prec == NULL)
		spaces = add_space(lkd_list->content, to_remplace);
	else if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-') && prec != NULL)
		spaces = add_space(lkd_list->content, prec);
	free(lkd_list->content);
	if (tmp != NULL)
	{
		if (spaces != NULL)
			free(spaces);
		free(to_remplace);
		lkd_list->content = tmp;
	}
	else if (spaces != NULL)
	{
		if (prec != NULL)
			free(prec);
		free(to_remplace);
		lkd_list->content = spaces;
	}
	else if (prec != NULL)
	{
		free(to_remplace);
		lkd_list->content = prec;
	}
	else
		lkd_list->content = to_remplace;
	return (0);
}
