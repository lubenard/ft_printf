/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:58:03 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/29 11:14:01 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*join_str(char *to_remplace, int length, int minus, char fill)
{
	int		length_remplace;
	char	*to_join;
	char	*tmp;

	length_remplace = ft_strlen(to_remplace);
	if (length - length_remplace < 0)
		length *= -1;
	if (!(to_join = ft_strnew(length - length_remplace)))
		return (NULL);
	to_join = ft_fill(to_join, fill, length - length_remplace);
	if (minus == 1)
		tmp = ft_strjoin(to_remplace, to_join);
	else
		tmp = ft_strjoin(to_join, to_remplace);
	free(to_join);
	return (tmp);
}

char	*join_str_neg(char *to_remplace, int length)
{
	int		length_remplace;
	char	*to_join;
	short	i;

	i = 1;
	length_remplace = ft_strlen(to_remplace);
	if (!(to_join = ft_strnew(length - length_remplace)))
		return (NULL);
	to_join[0] = '-';
	while (i < length - length_remplace)
		to_join[i++] = '0';
	to_remplace[0] = '0';
	to_remplace = ft_strjoin(to_join, to_remplace);
	free(to_join);
	return (to_remplace);
}

char	*extract_number(char *str)
{
	int		i;
	int		e;
	char	*ret;

	e = 0;
	i = 0;
	while (!ft_isdigit(str[i]) && str[i] != '-' && str[i])
		++i;
	e = i;
	if (str[e] == '-')
		++e;
	while (ft_isdigit(str[e]) && str[e])
		++e;
	ret = ft_strsub(str, i, e);
	return (ret);
}

int		detect_zero(char *str)
{
	if (str[0] == '-')
	{
		if (str[1] == '0')
		{
			free(str);
			return (1);
		}
	}
	else if (str[0] == '0')
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

char	*add_space(char *str, char *to_remplace)
{
	char	*sub;
	int		length;
	int		minus;

	minus = 0;
	sub = extract_number(str);
	if (sub[0] == '-')
		minus = 1;
	length = ft_atoi(sub);
	if (minus == 0 && detect_zero(sub) == 1)
		return (join_str(to_remplace, length, minus, '0'));
	else
		return (join_str(to_remplace, length, minus, ' '));
	return (NULL);
}
