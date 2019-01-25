/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:47:20 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/25 12:43:37 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_word		*new_maillon()
{
	t_word *new_element;

	if (!(new_element = (t_word *)malloc(sizeof(t_word))))
		return (NULL);
	new_element->next = NULL;
	return (new_element);
}

int			parsing(char **str)
{
	t_word *lkd_list;
	t_word *new_element;
	t_word *tmp;
	int		i;
	int		e;

	i = 0;
	e = 0;
	lkd_list = new_maillon();
	tmp = lkd_list;
	while (str[i][0])
	{
		printf("Element read: %s\n", str[i]);
		lkd_list->content = str[i];
		if (str[i + 1][0])
		{
			new_element = new_maillon();
			lkd_list->next = new_element;
			lkd_list = lkd_list->next;
		}
		i++;
	}
	void *test = lkd_list->content;
	printf("what ?? %s\n", ((char *)test));
	return (0);
}
