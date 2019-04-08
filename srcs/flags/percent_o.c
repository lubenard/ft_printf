/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:43:35 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/08 17:53:40 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*convert_in_octal(unsigned long long value)
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

char		*get_option_o(va_list ap, t_word *lkd_list)
{
	if (ft_strstr(lkd_list->content, "ll") != NULL)
		return (convert_in_octal(va_arg(ap, unsigned long long)));
	else if (ft_strstr(lkd_list->content, "hh") != NULL)
		return (convert_in_octal((unsigned char)va_arg(ap, unsigned int)));
	else if (ft_strchr(lkd_list->content, 'l') != -1)
		return (convert_in_octal(va_arg(ap, unsigned long)));
	else if (ft_strchr(lkd_list->content, 'h') != -1)
		return (convert_in_octal((unsigned short)va_arg(ap, int)));
	return (convert_in_octal(va_arg(ap, unsigned int)));
}


int			handle_return_o(t_word *lkd_list, char *prec,
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

int			percent_o(t_word *lkd_list, va_list ap)
{
	char				*to_remplace;
	int					i;
	char				*prec;
	char				*spaces;

	i = 0;
	prec = NULL;
	spaces = NULL;
	to_remplace = get_option_o(ap, lkd_list);
	if (ft_strcmp(to_remplace, "0") == 0)
	{
		if ((ft_strstr(lkd_list->content, ".0")
	|| detect_prec(lkd_list->content, 0) == -1) && ft_strchr(lkd_list->content, '#') == -1)
		{
			to_remplace = ft_strdup("");
		}
		else
		{
			lkd_list->is_malloc = 0;
			lkd_list->content = "0\0";
			return (0);
		}
	}
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		prec = precision(lkd_list->content, to_remplace, i, 0);
	if (((ft_isdigit(lkd_list->content[1]) || ft_isdigit(lkd_list->content[2])) || ft_strchr(lkd_list->content, '-'))
			&& prec == NULL)
			spaces = add_space(lkd_list, to_remplace);
	else if (((ft_isdigit(lkd_list->content[1]) || ft_isdigit(lkd_list->content[2])) || ft_strchr(lkd_list->content, '-'))
			&& prec != NULL)
		spaces = add_space(lkd_list, prec);
	//printf(", to_remplace = '%s' , prec = '%s' spaces = '%s'\n",to_remplace, prec, spaces);

	lkd_list->content = add_zero_x(lkd_list, to_remplace, prec, spaces);
	return (0);
//	return (handle_return_o(lkd_list, prec, spaces, to_remplace));
}
