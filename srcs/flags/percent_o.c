/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:43:35 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/07 04:41:50 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned long long		get_option_o(va_list ap, t_word *lkd_list)
{
	if (ft_strstr(lkd_list->content, "ll") != NULL)
		return (va_arg(ap, unsigned long long));
	else if (ft_strstr(lkd_list->content, "hh") != NULL)
		return ((short)va_arg(ap, unsigned int));
	else if (ft_strchr(lkd_list->content, 'l') != -1)
		return (va_arg(ap, unsigned long));
	else if (ft_strchr(lkd_list->content, 'h') != -1)
		return ((short)va_arg(ap, int));
	return (va_arg(ap, unsigned int));
}

char					*convert_in_octal(unsigned long long value)
{
	unsigned long long		i;
	unsigned long long		octal_num;

	octal_num = 0;
	i = 1;
	while (value != 0)
	{
		octal_num += (value % 8) * i;
		value /= 8;
		i *= 10;
	}
	return (ft_itoa_ulong(octal_num));
}

int						handle_return_o(t_word *lkd_list, char *prec,
		char *spaces, char *to_remplace)
{
	free(lkd_list->content);
	if (spaces != NULL)
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

int						percent_o(t_word *lkd_list, va_list ap)
{
	unsigned long long	value;
	char				*to_remplace;
	int					i;
	char				*prec;
	char				*spaces;

	i = 0;
	prec = NULL;
	spaces = NULL;
	value = get_option_o(ap, lkd_list);
	to_remplace = convert_in_octal(value);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		prec = precision(lkd_list->content, to_remplace, i, 0);
	if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
			&& prec == NULL)
		spaces = add_space(lkd_list->content, to_remplace);
	else if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
			&& prec != NULL)
		spaces = add_space(lkd_list->content, prec);
	return (handle_return_o(lkd_list, prec, spaces, to_remplace));
}
