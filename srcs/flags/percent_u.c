/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:38:58 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/25 20:59:21 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned int		negative_number(unsigned int nbr)
{
	if (nbr < 0)
		return(UINT_MAX - nbr);
	else if (nbr > UINT_MAX)
		return(UINT_MAX);
	return(nbr);
}

int		percent_u(t_word *lkd_list, va_list ap)
{
	unsigned int	value;
	int				i;
	char			*to_remplace;

	i = 0;
	value = negative_number(va_arg(ap, unsigned int));
	to_remplace = ft_itoa_long(value);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		to_remplace = precision(lkd_list->content, to_remplace, i, 0);
	if (lkd_list->content[1] != 'u')
	{
		if ((to_remplace = add_space(lkd_list->content, to_remplace)) == NULL)
			return (-1);
	}
	lkd_list->content = to_remplace;
	return (0);
}
