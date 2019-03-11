/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 19:36:29 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/11 14:19:44 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	//printf("><><><<><><><><><>< %lu\n", len + 1);
	while (i < len)
	{
		//printf(">>>>>>>>>> %zu\n", i);
		ret[i] = s[start + i];
		++i;
	}
	//printf("<<<<<<<<< %zu\n", i + 1);
	ret[i + 1] = '\0';
	return (ret);
}
