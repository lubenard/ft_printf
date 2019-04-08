/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:58:03 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/08 15:37:39 by lubenard         ###   ########.fr       */
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

char	*add_space(t_word *lkd_list, char *to_remplace)
{
	int		minus;

	minus = 0;
	if (ft_strchr(lkd_list->content, '-') > 0)
		minus = 1;
	if (lkd_list->null_char == 1)
		lkd_list->spaces--;
	if (lkd_list->spaces == 0)
		return (ft_strdup(to_remplace));
//	printf("length = %d, minus = %d sub = %s\n", lkd_list->spaces, minus, lkd_list->spaces_char);
	if (minus == 0 && detect_zero(lkd_list->spaces_char) == 1)
	{
//		printf(" >>>>>>> %c\n", to_remplace[0]);
		//if ((to_remplace[0] == '-' || to_remplace[0] == '+') && str[ft_strlen(str) - 1] == 'd')
		//	return (join_str2(to_remplace, length, minus, '0'));
			return (join_str(to_remplace, lkd_list->spaces, minus, '0'));
	}
	else
	{
		//printf("Ou par ici\n");
		return (join_str(to_remplace, lkd_list->spaces, minus, ' '));
	}
	return (NULL);
}
