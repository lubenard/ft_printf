/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:32:32 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/22 15:34:56 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_strstr(char const *str, char const *to_find)	
{
	int i;
	int j;

	i = 0;
	if (!str[0] && !to_find[0])
		return ((char *)str);
	if (!str[0] && to_find[0])
		return (0);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j])
			++j;
		if (!to_find[j])
			return ((char *)str + i);
		++i;
	}
	if (!str[i] && !to_find[j])
		return (0);
	return (0);
}

