/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:41:36 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/29 17:27:16 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*add_space(char *str, char *to_remplace)
{
	int		i;
	char	*sub;
	int		length;
	char	*to_join;
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
		if (!(to_join = (char *)malloc(sizeof(char) * length - ft_strlen(to_remplace))))
			return (NULL);
		to_join[length - ft_strlen(to_remplace)] = '\0';
		to_join = ft_fill(to_join, ' ', length - ft_strlen(to_remplace));
		to_remplace = (i > 1) ? ft_strjoin(to_remplace, to_join) : ft_strjoin(to_join, to_remplace);
	}
	return (to_remplace);
}

int		percent_s(t_word *lkd_list, va_list ap)
{
	char *to_remplace;
	void *content;
	char *str;

	to_remplace = va_arg(ap, char *);
	content = lkd_list->content;
	str = (char *)content;
	if (str[1] == 's')
		lkd_list->content = to_remplace;
	else
	{
		if ((to_remplace = add_space(str, to_remplace)) == NULL)
			return (-1);
		lkd_list->content = to_remplace;
	}
	return (0);
}
