/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:56:51 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/31 22:51:36 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*reduce_str(char *to_remplace, int length)
{
	int		i;
	char	*copy;

	i = 0;
	if (!(copy = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	while (i < length)
	{
		copy[i] = to_remplace[i];
		i++;
	}
	return (copy);
}

char	*precision(char *content, char *to_remplace, int i)
{
	char	*sub;
	int		length;
	int		j;

	j = i;
	length = 0;
	while (content[i] > 47 && content[i] < 58)
		++i;
	sub = ft_strsub(content, ++j, i);
	length = ft_atoi(sub);
	if (ft_strlen(to_remplace) <= length)
		return (to_remplace);
	else
		to_remplace = reduce_str(to_remplace, length);
	return (to_remplace);
}
