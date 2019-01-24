/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:47:20 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/24 18:15:02 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_word		*new_maillon()
{
	t_word *new_element;

	if (!(new_element = (t_word *)malloc(sizeof(t_word))))
		return (NULL);
	//new_element->next = NULL;
	return (new_element);
}

int			parsing(char **str)
{
	t_word *lkd_list;
	//t_word *new_element;
	int		i;
	int		e;
	
	i = 0;
	e = 0;
	lkd_list = new_maillon();
	while (str[i])
	{
		printf("Element read: %s\n", str[i]);
		i++;
	}
	return (0);
}
