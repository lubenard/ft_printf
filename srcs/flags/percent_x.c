/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:23:03 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/25 18:29:54 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*join_str_x(char *to_remplace, int length, int minus, char fill)
{
	int		length_remplace;
	char	*to_join;
	char	*tmp;

	length_remplace = ft_strlen(to_remplace);
	if (!(to_join = (char *)malloc(sizeof(char) * length - length_remplace \
					+ 1)))
		return (NULL);
	to_join[length - length_remplace] = '\0';
	to_join = ft_fill(to_join, fill, length - length_remplace);
	if (minus > 1)
	{
	//	printf("Hello les amigos\n");
		tmp = ft_strjoin(to_remplace, to_join);
	}
	else
	{
	//	printf("c'est la remontadaaaaa\n");
		tmp = ft_strjoin(to_join, to_remplace);
	}
	free(to_join);
	return (tmp);
}

char	*join_str_neg_x(char *to_remplace, int length)
{
	int		length_remplace;
	char	*to_join;
	short	i;

	i = 1;
	length_remplace = ft_strlen(to_remplace);
	if (!(to_join = (char *)malloc(sizeof(char) * length - length_remplace \
				+ 1)))
		return (NULL);
	to_join[length - length_remplace] = '\0';
	to_join[0] = '-';
	while (i < length - length_remplace)
		to_join[i++] = '0';
	to_remplace[0] = '0';
	to_remplace = ft_strjoin(to_join, to_remplace);
	free(to_join);
	return (to_remplace);
}

char	*ret_add_space_x(char *to_remplace, int length, char *sub, int minus)
{
	char	*tmp;

	free(sub);
	tmp = NULL;
	if (ft_strlen(to_remplace) < length)
	{
		//printf("Bruh 3\n");
		tmp = join_str_x(to_remplace, length, minus, ' ');
	}
	else
	{
	//	printf("Bruh 2\n");
		tmp = ft_strdup(to_remplace);
	}
	if (to_remplace != NULL)
		free(to_remplace);
	return (tmp);
}

char	*ret_add_space2_x(char *to_remplace, int length,
		char *sub, int minus)
{
	char	*tmp;

	free(sub);
	tmp = NULL;
	//printf("%d vs %d\n", ft_strlen(to_remplace), length);
	if (ft_strlen(to_remplace) < length)
	{
	//	printf("Et la ?\n");
		tmp = join_str_x(to_remplace, length, minus, ' ');
	}
	else
	{
	//	printf("Bruh 1\n");
		tmp = ft_strdup(to_remplace);
	}
	return (tmp);
}

char	*extract_number_x(char *str)
{
	int		i;
	int		e;
	char	*ret;

	e = 0;
	i = 0;
	while (!ft_isdigit(str[i]) && str[i] != '-')
		++i;
	e = i;
	if (str[e] == '-')
		++e;
	while (ft_isdigit(str[e]))
		++e;
	ret = ft_strsub(str, i, e - 2);
	return (ret);
}

char	*add_space_x(char *str, char *to_remplace)
{
	char	*sub;
	int		length;
	int		minus;
	char	*tmp;

	tmp = NULL;
	minus = 1;
	if (str[1] == '-')
		++minus;
	sub = extract_number_x(str);
	length = ft_atoi(sub);
	//printf("sub = %s\nlenght = %d, to_remplace = %s\n", sub, length, to_remplace);
	//printf("%c %c %d %d\n", to_remplace[0], sub[0], ft_strchr(str, '-'), ft_strchr(str, '.'));
	if (to_remplace[0] == '-' && sub[0] == '0'
	&& ft_strchr(str, '-') == -1 && ft_strchr(str, '.') == -1)
	{
	//	printf("Je rentre ici\n");
		tmp = join_str_neg_x(to_remplace, length);
	}
	else if (to_remplace[0] != '0' && sub[0] == '0' && ft_strchr(str, '-') == -1
	&& ft_strchr(str, '.') == -1)
	{
	//	printf("Je rentre la\n");
		tmp = join_str_x(to_remplace, length, minus, '0');
	}
	return ((tmp != NULL) ? ret_add_space_x(tmp, length, sub, minus)
			: ret_add_space2_x(to_remplace, length, sub, minus));
}

char		*get_option_x(va_list ap, t_word *lkd_list)
{
	if (ft_strstr(lkd_list->content, "ll") != NULL)
		return (convert_into_hexa(va_arg(ap, long long)));
	else if (ft_strstr(lkd_list->content, "hh") != NULL)
		return (convert_into_hexa(va_arg(ap, int)));
	else if (ft_strchr(lkd_list->content, 'l') != -1)
		return (convert_into_hexa(va_arg(ap, unsigned long)));
	else if (ft_strchr(lkd_list->content, 'h') != -1)
		return (convert_into_hexa(va_arg(ap, unsigned int)));
	else
		return (convert_into_hexa(va_arg(ap, unsigned int)));
}

char	*handle_return_x(t_word *lkd_list, char *to_remplace, char *spaces, char *prec)
{
	char	*tmp;
	int		sharp;

	sharp = ft_strchr(lkd_list->content, '#');
	tmp = NULL;
	if (spaces != NULL || prec != NULL)
	{
		free(to_remplace);
		if (spaces != NULL)
			return (spaces);
		else if (prec != NULL)
			return (prec);
	}
	return (to_remplace);
}

char	*percent_x(t_word *lkd_list, va_list ap, short option)
{
	char	*to_remplace;
	int		i;
	char	*prec;
	char	*spaces;
	int		sharp;

	sharp = ft_strchr(lkd_list->content, '#');
	i = 0;
	prec = NULL;
	spaces = NULL;
	to_remplace = get_option_x(ap, lkd_list);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		prec = precision(lkd_list->content, to_remplace, i, 0);
	if (sharp != -1 && prec == NULL && ft_strcmp(to_remplace, "0") != 0)
	{
		prec = ft_strjoin("0x", to_remplace);
	}
	else if (sharp != -1 && prec != NULL && ft_strcmp(prec, "0") != 0)
	{
		free(prec);
		prec = ft_strjoin("0x", prec);
	}
	if ((ft_isdigit(lkd_list->content[1]) || ft_isdigit(lkd_list->content[2]) || lkd_list->content[1] == '-' || lkd_list->content[2] == '-') && prec == NULL)
	{
	//	printf("Je rentre pas ici\n");
		spaces = add_space_x(lkd_list->content, to_remplace);
	}
	else if ((ft_isdigit(lkd_list->content[1]) || ft_isdigit(lkd_list->content[2]) || lkd_list->content[1] == '-' || lkd_list->content[2] == '-') && prec != NULL)
	{
	//	printf("ici non plus\n");
		spaces = add_space_x(lkd_list->content, prec);
	}
		free(lkd_list->content);
	if (option == 1)
		return (handle_return_x(lkd_list, to_remplace, spaces, prec));
	lkd_list->content = handle_return_x(lkd_list, to_remplace, spaces, prec);
	return (NULL);
}


