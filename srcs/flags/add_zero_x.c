/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zero_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:32:14 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/15 15:38:25 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*change_minus(char *str)
{
	int		i;
	char	tmp;
	int		e;
	//printf("Je rentre la\n");
	i = 0;
	e = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && i > 0)
		{
			while (str[e] == ' ')
				e++;
			tmp = str[e];
			str[e] = (str[i] == '-') ? '-' : '+';
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
	return (0);
}

char	*insert_zero(t_word *lkd_list, char *to_remplace, char *prec, char *spaces)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (spaces != NULL)
		tmp = spaces;
	else if (prec != NULL)
		tmp = prec;
	else if (spaces == NULL && prec == NULL)
		tmp = to_remplace;
	if (ft_strlen(tmp) == lkd_list->spaces && check_spaces(tmp) == 0)
		return (ft_strdup(tmp));
	//printf("Je suis la\n");
	if (tmp)
	{
		if (tmp[0] == ' ')
		{
			while (tmp[i + 1] == ' ')
				++i;
			tmp[i] = '0';
			if (tmp[ft_strlen(tmp) - 1] == ' ')
				tmp[ft_strlen(tmp) - 1] = '\0';
			return (ft_strdup(tmp));
		}
		else
			tmp = ft_strjoin("0", spaces);
		//printf("Here we are\n");
		if (tmp[ft_strlen(tmp) - 1] == ' ')
			tmp[ft_strlen(tmp) - 1] = '\0';
		return (tmp);
	}
	return (NULL);
}

char	*insert_spaces(int spaces, char *str)
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
		return (str);
	}
	else if (ft_strlen(str) >= spaces && check_spaces(str) == 0)
	{
		ft_strjoin("0x", str);
		return (str);
	}
	return (ft_strdup(str));
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

char	*add_zero_x(t_word *lkd_list, char *to_remplace, char *prec, char *spaces)
{
	if (ft_strchr(lkd_list->content, '#') == -1 ||
		check_null(prec, spaces, to_remplace) == -1)
	{
		if (lkd_list->content[ft_strlen(lkd_list->content) - 1] == 'o')
			free(lkd_list->content);
		if (spaces != NULL)
			return (ft_strdup(spaces));
		else if (prec != NULL)
			return (ft_strdup(prec));
		else
			return (ft_strdup(to_remplace));
	}
	//printf("to_remplace = %s spaces = %s prec = %s\n", to_remplace, spaces, prec);
	if (lkd_list->content[ft_strlen(lkd_list->content) - 1] == 'o')
	{
		free(lkd_list->content);
		//printf("je rentre la\n");
		return (insert_zero(lkd_list, to_remplace, prec, spaces));
	}
	if (spaces && check_spaces(spaces) == 0)
			return (ft_strjoin("0x", spaces));
	else if (prec && !spaces && check_spaces(prec) == 0)
		return (ft_strjoin("0x", prec));
	else if (!spaces && !prec && check_spaces(to_remplace) == 0)
		return (ft_strjoin("0x", to_remplace));
	else if (spaces && check_spaces(spaces) == -1)
		return (insert_spaces(lkd_list->spaces, spaces));
	else if (prec && check_spaces(prec) == -1)
		return (insert_spaces(lkd_list->spaces, prec));
	else if (!spaces && !prec && check_spaces(to_remplace) == -1)
		return (insert_spaces(lkd_list->spaces, to_remplace));
	return (NULL);
}
