/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rempl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <lubenard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 23:33:55 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/26 14:46:36 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	remplacage(t_word *lkd_list, va_list ap)
{
	void	*tmp;
	char	*tmp2;
	int		purcent_c;

	while (lkd_list)
	{
		tmp = lkd_list->content;
		tmp2 = ((char *)tmp);
		if (lkd_list->to_remplace == 1)
			if (tmp2[ft_strlen(tmp2) - 1] == 'd') //find last character of the string
				printf("Found d\n");
			if (tmp2[ft_strlen(tmp2) - 1] == 'c')
			{
				printf("Found c\n");
				purcent_c = va_arg(ap, int);
				lkd_list->content = &purcent_c;
			}
		lkd_list = lkd_list->next;
	}
}
