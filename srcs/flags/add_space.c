/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:58:03 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/06 18:32:38 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*join_str(char *to_remplace, int length, int minus, char fill)
{
	int		length_remplace;
	char	*to_join;
	char	*tmp;

	length_remplace = ft_strlen(to_remplace);
	if (length - length_remplace < 0)
		length *= -1;
	if (!(to_join = ft_strnew(length - length_remplace)))
		return (NULL);
	//printf("length - length_remplace = %d\n", length-length_remplace);
	to_join = ft_fill(to_join, fill, length - length_remplace);
	if (minus == 1)
		tmp = ft_strjoin(to_remplace, to_join);
	else
		tmp = ft_strjoin(to_join, to_remplace);
	free(to_join);
	//printf("Bruh = %s\n", tmp);
	return (tmp);
}

char	*join_str2(char *to_remplace, int length, int minus, char fill)
{
	int		length_remplace;
	char	*to_join;
	char	*tmp;
	char	firstchar;

	firstchar = to_remplace[0];
	to_remplace[0] = '0';
	length_remplace = ft_strlen(to_remplace);
	if (length - length_remplace < 0)
		length *= -1;
	if (!(to_join = ft_strnew(length - length_remplace)))
		return (NULL);
	//printf("length - length_remplace = %d\n", length-length_remplace);
	to_join = ft_fill(to_join, fill, length - length_remplace);
	if (minus == 1)
		tmp = ft_strjoin(to_remplace, to_join);
	else
		tmp = ft_strjoin(to_join, to_remplace);
	free(to_join);
	//printf("Bruh = %s\n", tmp);
	tmp[0] = firstchar;
	return (tmp);
}

char	*join_str_neg(char *to_remplace, int length)
{
	int		length_remplace;
	char	*to_join;
	short	i;

	i = 1;
	length_remplace = ft_strlen(to_remplace);
	if (!(to_join = ft_strnew(length - length_remplace)))
		return (NULL);
	to_join[0] = '-';
	while (i < length - length_remplace)
		to_join[i++] = '0';
	to_remplace[0] = '0';
	to_remplace = ft_strjoin(to_join, to_remplace);
	free(to_join);
	return (to_remplace);
}

char	*extract_number(char *str)
{
	int		i;
	int		e;
	char	*ret;

	e = 0;
	i = 0;
	while (!ft_isdigit(str[i]) && str[i])
	{
		if (str[i] == '.')
			return (ft_strdup("0"));
		++i;
	}
	e = i;
	while (ft_isdigit(str[e]) && str[e])
		++e;
	ret = ft_strsub(str, i, e - 1);
	return (ret);
}

int		detect_zero(char *str)
{
	if (str[0] == '-')
	{
		if (str[1] == '0')
			return (1);
	}
	else if (str[0] == '0')
		return (1);
	return (0);
}

char	*add_space(char *str, char *to_remplace)
{
	char	*sub;
	int		length;
	int		minus;

	minus = 0;
	sub = extract_number(str);
	if (ft_strchr(str, '-') > 0)
		minus = 1;
	length = ft_atoi(sub);
	if (length == 0)
		return (ft_strdup(to_remplace));
//	printf("length = %d, minus = %d sub = %s\n", length, minus, sub);
	if (minus == 0 && detect_zero(sub) == 1)
	{
//		printf(" >>>>>>> %c\n", to_remplace[0]);
		free(sub);
		//if ((to_remplace[0] == '-' || to_remplace[0] == '+') && str[ft_strlen(str) - 1] == 'd')
		//	return (join_str2(to_remplace, length, minus, '0'));
			return (join_str(to_remplace, length, minus, '0'));
	}
	else
	{
		//printf("Ou par ici\n");
		free(sub);
		return (join_str(to_remplace, length, minus, ' '));
	}
	return (NULL);
}
