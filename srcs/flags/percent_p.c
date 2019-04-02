/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:01:46 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/02 16:46:55 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** How to convert pointer address into %p ?
** Convert it in long unsigned int, then convert it in hexa
** Then add 0x before
** https://repl.it/repls/ValidBestFlashdrives
*/

void	free_elem_p(char *to_remplace, char *prec, char *spaces)
{
	if (prec != NULL || spaces != NULL)
		free(to_remplace);
	if (prec != NULL)
		free(prec);
}

void	handle_return(t_word *lkd_list, char *prec,
		char *to_remplace, char *spaces)
{
	free(lkd_list->content);
	if (spaces != NULL)
		lkd_list->content = spaces;
	else if (prec != NULL && spaces == NULL)
		lkd_list->content = prec;
	else
		lkd_list->content = to_remplace;
}

int		null_arg(int value, t_word *lkd_list)
{
	if (value == 0)
	{
		free(lkd_list->content);
		lkd_list->content = "0x0";
		lkd_list->is_malloc = 0;
		return (0);
	}
	return (1);
}

int		percent_p(t_word *lkd_list, va_list ap)
{
	char				*to_remplace;
	unsigned long		value;
	int					i;
	char				*prec;
	char				*spaces;

	prec = NULL;
	spaces = NULL;
	value = va_arg(ap, unsigned long);
	if (null_arg(value, lkd_list) == 0)
		return (0);
	to_remplace = conv_in_hexa_p(value);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		prec = precision(lkd_list->content, to_remplace, i, 0);
	if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
			&& prec == NULL)
		spaces = add_space(lkd_list->content, to_remplace);
	else if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
			&& prec != NULL)
		spaces = add_space(lkd_list->content, prec);
	handle_return(lkd_list, prec, to_remplace, spaces);
	free_elem_p(to_remplace, prec, spaces);
	return (0);
}
