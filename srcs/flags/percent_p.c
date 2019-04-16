/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:01:46 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/16 16:36:48 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** How to convert pointer address into %p ?
** Convert it in long unsigned int, then convert it in hexa
** Then add 0x before
** https://repl.it/repls/ValidBestFlashdrives
*/
char	 *change_sign(char *str)
{
	int i;
	int e;

	i = 0;
	e = 0;
	while (str[i] == ' ')
		i++;
	if (str[i + 2] == '0')
	{
		while (str[i + e] != 'x')
			e++;
		str[i + e] = '0';
		str[i + 1] = 'x';
		return (str);
	}
	return (str);
}

void	handle_return(t_word *lkd_list,
		char *to_remplace, char *spaces)
{
	if (spaces != NULL)
		free(to_remplace);
	free(lkd_list->content);
	if (spaces != NULL)
		lkd_list->content = change_sign(spaces);
	else
		lkd_list->content = change_sign(to_remplace);
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
	char				*spaces;
	char				*tmp;

	spaces = NULL;
	value = va_arg(ap, unsigned long);
	if (null_arg(value, lkd_list) == 0)
		return (0);
	to_remplace = conv_in_hexa_p(value);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
	{
		tmp = ft_strdup(to_remplace);
		free(to_remplace);
		to_remplace = precision(lkd_list->content, tmp, i, 0);
		free(tmp);
	}
	if (ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
		spaces = add_space(lkd_list, to_remplace);
	handle_return(lkd_list, to_remplace, spaces);
	return (0);
}
