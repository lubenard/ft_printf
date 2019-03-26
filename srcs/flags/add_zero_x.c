/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zero_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:32:14 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/26 23:18:10 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		check_spaces(char *str)
{
	int i;

	i = 0;
	if (str[i++] == ' ')
		return (1);
	return (0);

}

char	*insert_spaces(char *str)
{
	int i;

	i = 0;
	return (str);
}

char	*add_zero_x(char *content, char *to_remplace, char *prec, char *spaces)
{
	if (ft_strchr(content, '#') == -1)
	{
		if (spaces != NULL)
			return (spaces);
		else if (prec != NULL)
			return(prec);
		else
			return(to_remplace);
	}
	if (spaces != NULL && check_spaces(spaces) == 0)
		return (ft_strjoin("0x", spaces));
	else if (prec != NULL && check_spaces(prec) == 0)
		return (ft_strjoin("0x", prec));
	else if  (!spaces && !prec && check_spaces(to_remplace) == 0)
		return(ft_strjoin("0x", to_remplace));
	else if (spaces != NULL && check_spaces(spaces) == -1)
		return (insert_spaces(spaces));
	else if (prec != NULL && check_spaces(spaces) == -1)
		return (insert_spaces(prec));
	else if (!spaces && !prec && check_spaces(spaces) == -1)
		return (insert_spaces(prec));

	return (NULL);
}
