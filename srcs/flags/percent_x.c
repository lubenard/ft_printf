/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:23:03 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/12 17:41:33 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*get_option_x(va_list ap, t_word *lkd_list)
{
	if (ft_strstr(lkd_list->content, "ll") != NULL)
		return (convert_into_hexa(va_arg(ap, long long)));
	else if (ft_strstr(lkd_list->content, "hh") != NULL)
		return (convert_into_hexa(va_arg(ap, int)));
	else if (ft_strchr(lkd_list->content, 'l') != -1)
		return (convert_into_hexa(va_arg(ap, unsigned long)));
	else if (ft_strchr(lkd_list->content, 'h') != -1)
		return (convert_into_hexa(va_arg(ap, unsigned int)));
	else
		return (convert_into_hexa(va_arg(ap, unsigned int)));
}

char	*handle_return_x(t_word *lkd_list, char *to_remplace, char *spaces, char *prec)
{
	char	*tmp;
	int		sharp;

	sharp = ft_strchr(lkd_list->content, '#');
	tmp = NULL;
	if (spaces != NULL || prec != NULL)
	{
		free(to_remplace);
		if (spaces != NULL)
		{
			if (sharp != -1 && ft_strcmp(spaces, "0") != 0)
			{
				tmp = ft_strjoin("0x", spaces);
				free(spaces);
				return (tmp);
			}
			return (spaces);
		}
		else if (prec != NULL)
		{
			if (sharp != -1 && ft_strcmp(prec, "0") != 0)
			{
				tmp = ft_strjoin("0x", prec);
				free(prec);
				return (tmp);
			}
			return (prec);
		}
	}
	if (sharp != -1 && ft_strcmp(to_remplace, "0") != 0)
	{
		tmp = ft_strjoin("0x", to_remplace);
		free(to_remplace);
		return (tmp);
	}
	return (to_remplace);
}

char	*percent_x(t_word *lkd_list, va_list ap, short option)
{
	char	*to_remplace;
	int		i;
	char	*prec;
	char	*spaces;

	i = 0;
	prec = NULL;
	spaces = NULL;
	to_remplace = get_option_x(ap, lkd_list);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		prec = precision(lkd_list->content, to_remplace, i, 0);
	if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
			&& prec == NULL)
		spaces = add_space(lkd_list->content, to_remplace);
	else if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
			&& prec != NULL)
		spaces = add_space(lkd_list->content, prec);
	free(lkd_list->content);
	if (option == 1)
		return (handle_return_x(lkd_list, to_remplace, spaces, prec));
	lkd_list->content = handle_return_x(lkd_list, to_remplace, spaces, prec);
	return (NULL);
}

int		percent_x_maj(t_word *lkd_list, va_list ap)
{
	char	*to_remplace;
	int		j;

	j = 0;
	to_remplace = percent_x(lkd_list, ap, 1);
	while (to_remplace[j])
	{
		if (to_remplace[j] > 96 && to_remplace[j] < 123)
				to_remplace[j] -= 32;
		++j;
	}
	lkd_list->content = to_remplace;
	return (0);
}
