/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rempl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <lubenard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 23:33:55 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/27 22:56:16 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	remplacage(t_word *lkd_list, va_list ap)
{
	void	*tmp;
	char	*tmp2;
	t_word	*save_lkd;


	save_lkd = lkd_list;
	while (lkd_list)
	{
		tmp = lkd_list->content;
		tmp2 = ((char *)tmp);
		if (lkd_list->to_remplace == 1)
			if (tmp2[ft_strlen(tmp2) - 1] == 's') //find last character of the string
				percent_s(lkd_list, ap);
			if (tmp2[ft_strlen(tmp2) - 1] == 'c')
				percent_c(lkd_list, ap);
		lkd_list = lkd_list->next;
	}
	//affichage (temporaire, ce sera a supprimer pour la suite)
	while (save_lkd)
	{
		void *var;
		var = save_lkd->content;
		printf("%s", (char *)var);
		save_lkd = save_lkd->next;
	}
}
