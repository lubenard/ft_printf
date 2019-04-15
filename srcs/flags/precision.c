/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:56:51 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/15 15:30:48 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		detect_prec(char *str, int mode)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			//printf("ce truc vaut %c et vaut  %c\n", str[i + 1], str[i - 1]);
			//printf("ft_isdigit(+1) = %d et -1 = %d\n", ft_isdigit(str[i+ 1]), ft_isdigit(str[i- 1]));
			if (!ft_isdigit(str[i + 1])&& mode == 0)
				return (-1);
			if (ft_isdigit(str[i - 1]) && mode == 1)
				return (0);
			else
				return (-1);
		}
		++i;
	}
	return (1);
}

char	*reduce_str(char *to_remplace, int length)
{
	int		i;
	char	*copy;

	i = 0;
	if (!(copy = ft_strnew(length)))
		return (NULL);
	while (i < length)
	{
		copy[i] = to_remplace[i];
		++i;
	}
	return (copy);
}

char	*mode_1(char *to_remplace, int length, char *sub)
{
	char *tmp;

	tmp = NULL;
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

char	*mode_0(char *to_remplace, int length, char *sub)
{
	char *tmp;

	tmp = NULL;
	if (ft_strlen(to_remplace) >= length)
	{
		free(sub);
		return (ft_strdup(to_remplace));
	}
	else if (ft_strchr(to_remplace, '-') != -1)
		tmp = join_str_neg(to_remplace, ++length);
	else
		tmp = join_str(to_remplace, length, 0, '0');
	free(sub);
	return (tmp);
}

char	*precision(char *content, char *to_remplace, int i, int mode)
{
	char	*sub;
	int		length;
	int		j;
	int		k;

	j = i + 1;
	length = 0;
	++i;
	k = i;
	while (content[i] > 47 && content[i] < 58)
		++i;
	sub = ft_strsub(content, j, i - k);
	length = ft_atoi(sub);
	if (mode == 1)
		return (mode_1(to_remplace, length, sub));
	else if (mode == 0)
		return (mode_0(to_remplace, length, sub));
	return (NULL);
}
