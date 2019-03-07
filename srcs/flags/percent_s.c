/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:41:36 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/07 03:03:28 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_return_s(t_word *lkd_list, char *spaces,
		char *prec, char *to_remplace)
{
	free(lkd_list->content);
	if (spaces != NULL)
	{
		lkd_list->is_malloc = 1;
		lkd_list->content = spaces;
	}
	else if (prec != NULL)
	{
		lkd_list->is_malloc = 1;
		lkd_list->content = prec;
	}
	else
		lkd_list->content = to_remplace;
}

int		percent_s(t_word *lkd_list, va_list ap)
{
	char	*to_remplace;
	int		i;
	char	*prec;
	char	*spaces;

	i = 0;
	prec = NULL;
	spaces = NULL;
	lkd_list->is_malloc = 0;
	to_remplace = va_arg(ap, char *);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		prec = precision(lkd_list->content, to_remplace, i, 1);
	if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
		&& prec == NULL)
		spaces = add_space(lkd_list->content, to_remplace);
	else if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
		&& prec != NULL)
		spaces = add_space(lkd_list->content, prec);
	handle_return_s(lkd_list, spaces, prec, to_remplace);
	return (0);
}
