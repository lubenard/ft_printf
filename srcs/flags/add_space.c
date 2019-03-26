/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:58:03 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/26 12:33:09 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*join_str(char *to_remplace, int length, int minus, char fill)
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
		printf("Hello les amigos\n");
		tmp = ft_strjoin(to_remplace, to_join);
	}
	else
	{
		printf("c'est la remontadaaaaa\n");
		tmp = ft_strjoin(to_join, to_remplace);
	}
	free(to_join);
	return (tmp);
}

char	*join_str_neg(char *to_remplace, int length)
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

char	*ret_add_space(char *to_remplace, int length, char *sub, int minus)
{
	char	*tmp;

	free(sub);
	tmp = NULL;
	if (ft_strlen(to_remplace) < length)
	{
		printf("Bruh 3\n");
		tmp = join_str(to_remplace, length, minus, ' ');
	}
	else
	{
		printf("Bruh 2\n");
		tmp = ft_strdup(to_remplace);
	}
	if (to_remplace != NULL)
		free(to_remplace);
	return (tmp);
}

char	*ret_add_space2(char *to_remplace, int length,
		char *sub, int minus)
{
	char	*tmp;

	free(sub);
	tmp = NULL;
	printf("%d vs %d\n", ft_strlen(to_remplace), length);
	if (ft_strlen(to_remplace) < length)
	{
		printf("Et la ?\n");
		tmp = join_str(to_remplace, length, minus, ' ');
	}
	else
	{
		printf("Bruh 1\n");
		tmp = ft_strdup(to_remplace);
	}
	return (tmp);
}

char	*extract_number(char *str)
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

char	*add_space2(char *str, char *to_remplace)
{
	char	*sub;
	int		length;
	int		minus;
	char	*tmp;

	tmp = NULL;
	minus = 1;
	if (str[1] == '-')
		++minus;
	sub = extract_number(str);
	length = ft_atoi(sub);
	printf("length %s\nlenght = %d, to_remplace = %s\n", sub, length, to_remplace);
	printf("%c %c %d %d\n", to_remplace[0], sub[0], ft_strchr(str, '-'), ft_strchr(str, '.'));
	if (to_remplace[0] == '-' && sub[0] == '0'
	&& ft_strchr(str, '-') == -1 && ft_strchr(str, '.') == -1)
	{
		printf("Je rentre ici\n");
		tmp = join_str_neg(to_remplace, length);
	}
	else if (to_remplace[0] != '0' && sub[0] == '0' && ft_strchr(str, '-') == -1
	&& ft_strchr(str, '.') == -1)
	{
		printf("Je rentre la\n");
		tmp = join_str(to_remplace, length, minus, '0');
	}
	return ((tmp != NULL) ? ret_add_space(tmp, length, sub, minus)
			: ret_add_space2(to_remplace, length, sub, minus));
}

char	*add_space(char *str, char *to_remplace)
{
	char	*sub;
	int		length;
	int		minus;
	char	*tmp;

	tmp = NULL;
	minus = 1;
	if (str[1] == '-')
		++minus;
	sub = extract_number(str);
	length = ft_atoi(sub);
	printf("length %s\nlenght = %d, to_remplace = %s\n", sub, length, to_remplace);
	printf("%c %c %d %d\n", to_remplace[0], sub[0], ft_strchr(str, '-'), ft_strchr(str, '.'));
	if (to_remplace[0] == '-' && sub[0] == '0'
	&& ft_strchr(str, '-') == -1 && ft_strchr(str, '.') == -1)
	{
		printf("Je rentre ici\n");
		tmp = join_str_neg(to_remplace, length);
	}
	else if (to_remplace[0] != '0' && sub[0] == '0' && ft_strchr(str, '-') == -1
	&& ft_strchr(str, '.') == -1)
	{
		printf("Je rentre la\n");
		tmp = join_str(to_remplace, length, minus, '0');
	}
	return ((tmp != NULL) ? ret_add_space(tmp, length, sub, minus)
			: ret_add_space2(to_remplace, length, sub, minus));
}


