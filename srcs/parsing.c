/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:47:20 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/08 15:12:12 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*splitting(const char *str)
{
	static int	i = 0;
	int			e;

	e = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%' && str[i] != '{')
		{
			while (str[i + e] != '%' && str[i + e] != '{' && str[i + e] != '\0')
				++e;
			i += e;
			return (ft_strsub(str, i - e, e));
		}
		else
		{
			++i;
			while (ft_strchr("cspdiouxX}%", str[i + e]) == -1)
				++e;
			i += e + 1;
			return (ft_strsub(str, i - e - 2, e + 2));
		}
	}
	i = 0;
	return (NULL);
}

t_word		*new_maillon(void)
{
	t_word	*new_element;

	if (!(new_element = (t_word *)malloc(sizeof(t_word))))
		return (NULL);
	new_element->content = NULL;
	new_element->is_malloc = 1;
	new_element->manual_len = -1;
	new_element->null_char = 0;
	new_element->spaces_char = NULL;
	new_element->spaces = 0;
	new_element->next = NULL;
	return (new_element);
}

void		free_lkd_lst(t_word *lkd_list)
{
	t_word *tmp;

	while (lkd_list)
	{
		tmp = lkd_list;
		lkd_list = lkd_list->next;
		if (tmp->is_malloc == 1)
			free(tmp->content);
		free(tmp->spaces_char);
		free(tmp);
	}
}

int			parsing(const char *str, va_list ap, int fd)
{
	t_word	*lkd_list;
	t_word	*new_element;
	t_word	*tmp;
	int		total_length;
	char	*str2;

	lkd_list = new_maillon();
	tmp = lkd_list;
	total_length = 0;
	while ((str2 = splitting(str)) != NULL)
	{
		lkd_list->content = str2;
		lkd_list->spaces_char = extract_number(str2);
		lkd_list->spaces = ft_atoi(lkd_list->spaces_char);
		if (str2[0] == '%' || str2[0] == '{')
			remplacage(lkd_list, ap);
		new_element = new_maillon();
		lkd_list->next = new_element;
		if (lkd_list->content != NULL)
			total_length += (fd == 1) ? ft_putstr(1, lkd_list)
			: ft_putstr(fd, lkd_list);
		lkd_list = lkd_list->next;
	}
	free_lkd_lst(tmp);
	return (total_length);
}
