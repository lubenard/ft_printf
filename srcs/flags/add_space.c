/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:58:03 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/30 16:00:36 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*join_strings(char *to_remplace, int length, int i)
{
	int		length_remplace;
	char	*to_join;

	length_remplace = ft_strlen(to_remplace);
	if (!(to_join = (char *)malloc(sizeof(char) * length - length_remplace)))
		return (NULL);
	to_join[length - length_remplace] = '\0';
	to_join = ft_fill(to_join, ' ', length - length_remplace);
	if (i > 1)
		to_remplace = ft_strjoin(to_remplace, to_join);
	else
		ft_strjoin(to_join, to_remplace);
	return (to_remplace);
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
	sub = ft_strsub(str, minus, i - 1);
	length = ft_atoi(sub);
	free(sub);
	if (ft_strlen(to_remplace) < length)
	{
		to_remplace = join_strings(to_remplace, length, i);
	}
	return (to_remplace);
}
