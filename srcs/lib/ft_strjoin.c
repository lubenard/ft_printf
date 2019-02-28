/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 12:09:43 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/28 19:42:07 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		e;

	if (!s1 || !s2)
		return (0);
	i = 0;
	e = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + \
						ft_strlen(s2)) + 1)))
		return (0);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[e])
	{
		ret[i + e] = s2[e];
		e++;
	}
	ret[i + e] = '\0';
	return (ret);
}
