/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:37:44 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/17 17:50:08 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** Here you will find all useless function i
** cannot put in there original file because
** of the norme.
*/

char	*return_x(t_word *lkd_list, char *zero_x, int option)
{
	if (option == 1)
		return (zero_x);
	lkd_list->content = zero_x;
	return (0);
}

int		check_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == ' ')
			return (-1);
	}
	return (0);
}
