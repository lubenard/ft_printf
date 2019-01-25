/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rempl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <lubenard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 23:33:55 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/26 00:26:09 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	remplacage(t_word *lkd_list)
{
	void *tmp;
	char *tmp2;

	while (lkd_list)
	{
		tmp = lkd_list->content;
		tmp2 = ((char *)tmp);
		if (lkd_list->to_remplace == 1)
			if (tmp2[ft_strlen(tmp2) - 1] == 'd') //find last character of the string
				printf("Found\n");
		lkd_list = lkd_list->next;
	}
}
