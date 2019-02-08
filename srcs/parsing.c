/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:47:20 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/08 11:50:15 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char		*splitting(char *str)
{
	static int i;
	int e;
	char *ret;

	e = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i] != '{')
			++i;
		printf("-----------\ne = %d\ni = %d\n-------------\n", e, i);
		ret = ft_strsub(str, e, i);
	}
	printf("ret = %s\n", ret);
	return (ret);
}

t_word		*new_maillon(void)
{
	t_word	*new_element;

	if (!(new_element = (t_word *)malloc(sizeof(t_word))))
		return (NULL);
	new_element->next = NULL;
	new_element->fd = 1;
	new_element->to_remplace = 0;
	return (new_element);
}

int			parsing(char *str, va_list ap)
{
	t_word	*lkd_list;
	t_word	*new_element;
	t_word	*tmp;
	int		i;
	int		e;
	char	*str2;

	i = 0;
	e = 0;
	lkd_list = new_maillon();
	tmp = lkd_list;
	while ((str2 = splitting(str)) != NULL)
	{
		lkd_list->content = str2;
		if (str2[0] == '%' || str2[0] == '{')
			lkd_list->to_remplace = 1;
		if (str2[0])
		{
			new_element = new_maillon();
			lkd_list->next = new_element;
			lkd_list = lkd_list->next;
		}
		++i;
	}
	remplacage(tmp, ap);
	while (tmp)
	{
		printf("Loop affichage lkd_list->content: '%s'\n", tmp->content);
		printf("Loop affichage lkd_list->to_remplace: %d\n", tmp->to_remplace);
		printf("Loop affichage lkd_list->next %p\n", tmp->next);
		printf("------------------------------------------------\n");
		tmp = tmp->next;
	}
	return (0);
}
