/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:23:03 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/07 05:10:06 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*convert_into_hexa(unsigned long long value)
{
	char			*ret;
	int				i;
	long long int	tmp;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * 11)))
		return (NULL);
	while (value != 0)
	{
		tmp = 0;
		tmp = value % 16;
		if (tmp < 10)
			ret[i] = tmp + 48;
		else
			ret[i] = tmp + 87;
		++i;
		value = value / 16;
	}
	ret[i] = '\0';
	return (rev(ret));
}

char	*handle_return_x(char *to_remplace, char *spaces, char *prec)
{
	if (spaces != NULL)
	{
		free(to_remplace);
		if (prec != NULL)
			free(prec);
		return (spaces);
	}
	else if (prec != NULL)
	{
		free(to_remplace);
		return (prec);
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
	to_remplace = convert_into_hexa(va_arg(ap, unsigned long long));
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
		return (handle_return_x(to_remplace, spaces, prec));
	lkd_list->content = handle_return_x(to_remplace, spaces, prec);
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
