/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:01:46 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/05 18:52:10 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** How to convert pointer address into %p ?
** Convert it in long unsigned int, then convert it in hexa
** Then add 0x before
** https://repl.it/repls/ValidBestFlashdrives
*/

char	*conv_in_hexa_ul(unsigned long value)
{
	char	*ret;
	int		i;
	int		tmp;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	while (value != 0)
	{
		tmp = 0;
		tmp = value % 16;
		if (tmp < 10)
			ret[i] = tmp + 48;
		else
			ret[i] = tmp + 87;
		++i;
		value = value / 16;
	}
	ret[i] = 'x';
	ret[++i] = '0';
	return (rev(ret));
}

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
	if (value == 0)
	{
		lkd_list->content = "0x0";
		lkd_list->is_malloc = 0;
		return (0);
	}
	to_remplace = conv_in_hexa_ul(value);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		prec = precision(lkd_list->content, to_remplace, i, 0);
	if (lkd_list->content[1] != 'p' && prec == NULL)
		spaces = add_space(lkd_list->content, to_remplace);
	else if (lkd_list->content[1] != 'p' && prec != NULL)
		spaces = add_space(lkd_list->content, prec);
	handle_return(lkd_list, prec, to_remplace, spaces);
	free_elem_p(to_remplace, prec, spaces);
	return (0);
}
