/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zero_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:32:14 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/02 21:52:24 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*change_minus(char *str)
{
	int		i;
	char	tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && i > 0 && str[i] != ' ')
		{
			tmp = str[0];
			str[0] = '-';
			str[i] = tmp;
		}
		++i;
	}
	return (str);
}

int		check_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == ' ')
			return (-1);
	}
	if (str[0] == '0' && str[1] == '0')
		return (-1);
	return (0);
}

char	*insert_spaces(char *str)
{
	int i;

	i = 0;
	if (str[i] == ' ')
	{
		while (str[i + 2] == ' ')
			++i;
		str[i] = '0';
		str[i + 1] = 'x';
	}
	else if (str[ft_strlen(str) - 1] == ' ')
	{
		str = ft_strjoin("0x", str);
		str[ft_strlen(str) - 1] = '\0';
		str[ft_strlen(str) - 1] = '\0';
	}
	else if (str[0] == '0' && str[1] == '0')
	{
		str[0] = '0';
		str[1] = 'x';
	}
	return (str);
}

int		check_null(char *prec, char *spaces, char *to_remplace)
{
	if (spaces != NULL)
	{
		if (ft_strcmp(spaces, "0") == 0)
			return (-1);
	}
	else if (prec != NULL)
	{
		free(to_remplace);
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

char	*add_zero_x(char *content, char *to_remplace, char *prec, char *spaces)
{
	if (ft_strchr(content, '#') == -1 ||
		check_null(prec, spaces, to_remplace) == -1)
	{
		if (spaces != NULL)
			return (spaces);
		else if (prec != NULL)
			return (ft_strdup(prec));
		else
			return (ft_strdup(to_remplace));
	}
	if (spaces != NULL && check_spaces(spaces) == 0)
		return (ft_strjoin("0x", spaces));
	else if (prec != NULL && check_spaces(prec) == 0)
		return (ft_strjoin("0x", prec));
	else if (!spaces && !prec && check_spaces(to_remplace) == 0)
		return (ft_strjoin("0x", to_remplace));
	else if (spaces != NULL && check_spaces(spaces) == -1)
		return (insert_spaces(spaces));
	else if (prec != NULL && check_spaces(spaces) == -1)
		return (insert_spaces(prec));
	else if (!spaces && !prec && check_spaces(to_remplace) == -1)
		return (insert_spaces(to_remplace));
	return (NULL);
}