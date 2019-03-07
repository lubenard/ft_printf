/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:58:03 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/07 06:57:43 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*join_str(char *to_remplace, int length, int minus, char fill)
{
	int		length_remplace;
	char	*to_join;
	char	*tmp;

	length_remplace = ft_strlen(to_remplace);
	if (!(to_join = (char *)malloc(sizeof(char) * length - length_remplace \
					+ 1)))
		return (NULL);
	to_join[length - length_remplace] = '\0';
	to_join = ft_fill(to_join, fill, length - length_remplace);
	if (minus > 1)
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
	if (!(to_join = (char *)malloc(sizeof(char) * length - length_remplace \
				+ 1)))
		return (NULL);
	to_join[length - length_remplace] = '\0';
	to_join[0] = '-';
	while (i < length - length_remplace)
		to_join[i++] = '0';
	to_remplace[0] = '0';
	to_remplace = ft_strjoin(to_join, to_remplace);
	free(to_join);
	return (to_remplace);
}

char	*ret_add_space(char *to_remplace, int length, char *sub, int minus)
{
	char	*tmp;

	free(sub);
	tmp = NULL;
	if (ft_strlen(to_remplace) < length)
		tmp = join_str(to_remplace, length, minus, ' ');
	else
		tmp = strdup(to_remplace);
	//free(to_remplace);
	return (tmp);
}

char	*add_space(char *str, char *to_remplace)
{
	int		i;
	char	*sub;
	int		length;
	int		minus;

	i = 1;
	minus = 1;
	if (str[1] == '-')
	{
		++minus;
		++i;
	}
	while (str[i] > 47 && str[i] < 58)
		++i;
	sub = ft_strsub(str, minus, i);
	length = ft_atoi(sub);
	if (to_remplace[0] == '-' && sub[0] == '0'
	&& ft_strchr(str, '-') == -1 && ft_strchr(str, '.') == -1)
		to_remplace = join_str_neg(to_remplace, length);
	else if (to_remplace[0] != '0'  && sub[0] == '0' && ft_strchr(str, '-') == -1
	&& ft_strchr(str, '.') == -1)
		to_remplace = join_str(to_remplace, length, minus, '0');
	return (ret_add_space(to_remplace, length, sub, minus));
}
