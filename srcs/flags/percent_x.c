/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:23:03 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/07 11:01:16 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*convert_into_hexa(int value)
{
	char	*ret;
	int		i;
	int		tmp;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * 10)))
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
	return (rev(ret));
}

int		percent_x(t_word *lkd_list, va_list ap)
{
	char			*to_remplace;
	void			*get_value;
	unsigned long	value;
	int				i;

	i = 0;
	get_value = va_arg(ap, void *);
	value = (unsigned long)get_value;
	to_remplace = convert_into_hexa(value);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		to_remplace = precision(lkd_list->content, to_remplace, i, 0);
	if (lkd_list->content[1] != 'x')
		to_remplace = add_space(lkd_list->content, to_remplace);
	lkd_list->content = to_remplace;
	return (0);
}

int		percent_x_maj(t_word *lkd_list, va_list ap)
{
	char			*to_remplace;
	void			*get_value;
	int				i;
	int				j;
	unsigned long	value;

	j = 0;
	i = 0;
	get_value = va_arg(ap, void *);
	value = (unsigned long)get_value;
	to_remplace = convert_into_hexa(value);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		to_remplace = precision(lkd_list->content, to_remplace, i, 0);
	if (lkd_list->content[1] != 'x')
		to_remplace = add_space(lkd_list->content, to_remplace);
	while (to_remplace[j])
	{
		if (to_remplace[j] > 96 && to_remplace[j] < 123)
			to_remplace[j] -= 32;
		++j;
	}
	lkd_list->content = to_remplace;
	return (0);
}
