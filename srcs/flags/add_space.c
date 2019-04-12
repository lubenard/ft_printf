/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:58:03 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/12 23:28:12 by lubenard         ###   ########.fr       */
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
	to_remplace[0] = fill;
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
		if (str[i] == '.' || str[i + 1] == '\0')
			return (ft_strdup("0"));
		++i;
	}
	//printf("Je suis sur le charactere %c et str vaut %s\n", str[i], str);
	if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '#' || str[i + 1] == ' ')
		i += 2;
	//printf("Je suis sur le charactere %c et str vaut %s\n", str[i], str);
	e = i;
	while (ft_isdigit(str[e]) && str[e])
	{
	//	printf("je decide d'avancer\n");
		++e;
	}
	ret = ft_strsub(str, i, e - 1);
	//printf("ret = %s\n", ret);
	return (ret);
}

int		detect_zero(t_word *lkd_list)
{
	int i;

	i = 0;
	while (lkd_list->content[i])
	{
		if (lkd_list->content[i] == '0' && lkd_list->spaces < 10
		&& lkd_list->content[i - 1] != '.')
			return (1);
		else
		{
			if (lkd_list->content[i] == '0'
			&& ft_isdigit(lkd_list->content[i - 1]) != '0'
			&& lkd_list->content[i + 1] > '0' && lkd_list->content[i + 1] < '9'
			&& lkd_list->content[i - 1] != '.')
				return (1);
		}
		i++;
	}
	return (0);
}

char	*add_space(t_word *lkd_list, char *to_remplace)
{
	int		minus;

//	printf("length = %d, sub = %s\n", lkd_list->spaces, lkd_list->spaces_char);
	minus = 0;
	if (ft_strchr(lkd_list->content, '-') > 0)
		minus = 1;
	if (lkd_list->null_char == 1)
		lkd_list->spaces--;
	if (lkd_list->spaces == 0)
		return (ft_strdup(to_remplace));
//	printf("length = %d, minus = %d sub = %s\n", lkd_list->spaces, minus, lkd_list->spaces_char);
//	printf("detect zero = %d\n", detect_zero(lkd_list));

	//printf("detect prec == %d\n", detect_prec(lkd_list->content, 0));
	if (minus == 0 && detect_zero(lkd_list) == 1 && detect_prec(lkd_list->content, 0) != -1)
	{
		return (join_str(to_remplace, lkd_list->spaces, minus, '0'));
	}
	else
	{
		return (join_str(to_remplace, lkd_list->spaces, minus, ' '));
	}
	return (NULL);
}
