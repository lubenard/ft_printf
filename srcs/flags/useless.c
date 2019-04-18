/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:37:44 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/18 13:01:39 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** Here you will find all useless function i
** cannot put in there original file because
** of the norme.
*/

char			*return_x(t_word *lkd_list, char *zero_x, int option)
{
	if (option == 1)
		return (zero_x);
	lkd_list->content = zero_x;
	return (0);
}

int				check_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == ' ')
			return (-1);
	}
	return (0);
}

t_percent_di	initialise_struct_di(void)
{
	t_percent_di struct_di;

	struct_di.spaces = NULL;
	struct_di.prec = NULL;
	struct_di.tmp = NULL;
	return (struct_di);
}

void			handle_ret_di2(t_percent_di *struct_di,
	t_word *lkd_list, char *to_remplace, int i)
{
	if (extract_prec(lkd_list->content, i) == ft_strlen(to_remplace)
	&& extract_prec(lkd_list->content, i) != 0
	&& ft_strchr(lkd_list->content, '+') == -1)
	{
		lkd_list->is_neg = 1;
		free(struct_di->spaces);
		struct_di->spaces = ft_strjoin("0", struct_di->prec);
	}
}

int				check_null(char *prec, char *spaces, char *to_remplace)
{
	if (spaces != NULL)
	{
		if (ft_strcmp(spaces, "0") == 0)
			return (-1);
	}
	else if (prec != NULL)
	{
		if (ft_strcmp(prec, "0") == 0)
			return (-1);
	}
	else if (to_remplace != NULL)
	{
		if (ft_strcmp(to_remplace, "0") == 0)
			return (-1);
	}
	return (0);
}
