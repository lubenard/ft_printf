/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:56:51 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/08 13:10:39 by lubenard         ###   ########.fr       */
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
		++i;
	}
	return (copy);
}

char	*mode_1(char *to_remplace, int length, char *sub, char *tmp)
{
	if (ft_strlen(to_remplace) <= length)
	{
		free(sub);
		return (ft_strdup(to_remplace));
	}
	else
		tmp = reduce_str(to_remplace, length);
	free(sub);
	return (tmp);
}

char	*mode_0(char *to_remplace, int length, char *sub, char *tmp)
{
	if (ft_strlen(to_remplace) >= length)
	{
		free(sub);
		return (to_remplace);
	}
	else if (ft_strchr(to_remplace, '-') != -1)
		tmp = join_str_neg(to_remplace, ++length);
	else
		tmp = join_str(to_remplace, length, 1, '0');
	free(sub);
	return (tmp);
}

char	*precision(char *content, char *to_remplace, int i, int mode)
{
	char	*sub;
	int		length;
	int		j;
	char	*tmp;

	j = i + 1;
	length = 0;
	++i;
	tmp = NULL;
	while (content[i] > 47 && content[i] < 58)
		++i;
	sub = ft_strsub(content, j, i);
	length = ft_atoi(sub);
	if (mode == 1)
		return (mode_1(to_remplace, length, sub, tmp));
	else if (mode == 0)
		return (mode_0(to_remplace, length, sub, tmp));
	return (tmp);
}
