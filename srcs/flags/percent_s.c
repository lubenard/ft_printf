/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:41:36 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/27 23:45:38 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char *add_space(char *str)
{
	int i;
	char *sub;
	int length;

	i = 0;
	while (str[i] > 47 && str[i] < 58)
		i++;
	sub = ft_strsub(str, 1, i);
	length = ft_atoi(str);
	free(sub);
	if (ft_strlen(str) < length)
	{
		ft_strjoin(old, new);
	}
	return (str);
}

void	percent_s(t_word *lkd_list, va_list ap)
{
	char *to_remplace;
	void *content;
	char *str;

	to_remplace = va_arg(ap, char *);
	content = lkd_list->content;
	str = (char *)content;
	if (str[1] == 's')
		lkd_list->content = &to_remplace[0];
	else if (str[1] > 47 && str[1] < 58)
		str = add_space(str);
}
