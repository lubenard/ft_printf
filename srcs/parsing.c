/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:47:20 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/21 17:37:40 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*splitting(const char *str)
{
	static int	i = 0;
	int			e;

	e = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%' && str[i] != '{')
		{
			while (str[i + e] != '%' && str[i + e] != '{' && str[i + e] != '\0')
				++e;
			i += e;
			return (ft_strsub(str, i - e, e));
		}
		else
		{
			while (ft_strchr("cspdiouxX", str[i + e]) == -1 && str[i] != '}')
				++e;
			i += e + 1;
			return (ft_strsub(str, i - e - 1, e + 1));
		}
	}
	return (NULL);
}

t_word		*new_maillon(void)
{
	t_word	*new_element;

	if (!(new_element = (t_word *)malloc(sizeof(t_word))))
		return (NULL);
	new_element->next = NULL;
	return (new_element);
}

int			parsing(const char *str, va_list ap)
{
	t_word	*lkd_list;
	t_word	*new_element;
	t_word	*tmp;
	char	*str2;

	lkd_list = new_maillon();
	tmp = lkd_list;
	while ((str2 = splitting(str)) != NULL)
	{
		lkd_list->content = str2;
		if (str2[0] == '%' || str2[0] == '{')
			remplacage(lkd_list, ap);
		new_element = new_maillon();
		lkd_list->next = new_element;
		if (lkd_list->content != NULL)
			ft_putstr(lkd_list->content);
		lkd_list = lkd_list->next;
	}
/*	while (tmp)
	{
		printf("Loop affichage lkd_list->content: '%s'\n", tmp->content);
		printf("Loop affichage lkd_list->next %p\n", tmp->next);
		printf("------------------------------------------------\n");
		tmp = tmp->next;
	}*/
	return (0);
}
