/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:01:12 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/15 14:43:20 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*get_option_d(va_list ap, t_word *lkd_list)
{
	if (ft_strstr(lkd_list->content, "ll") != NULL)
		return (ft_itoa_long(va_arg(ap, long long)));
	else if (ft_strstr(lkd_list->content, "hh") != NULL)
		return (ft_sstoa((char)va_arg(ap, int)));
	else if (ft_strchr(lkd_list->content, 'l') != -1)
		return (ft_itoa_long(va_arg(ap, long int)));
	else if (ft_strchr(lkd_list->content, 'h') != -1)
		return (ft_stoa((short)va_arg(ap, int)));
	else
		return (ft_itoa(va_arg(ap, int)));
}

int			handle_ret_di(t_percent_di struct_di, t_word *lkd_list,
		char *to_remplace)
{
	free(lkd_list->content);
	if (struct_di.spaces != NULL)
	{
		if (struct_di.prec != NULL)
			free(struct_di.prec);
		if (struct_di.tmp != NULL)
			free(struct_di.tmp);
		free(to_remplace);
		lkd_list->content = change_minus(struct_di.spaces);
	}
	else if (struct_di.tmp != NULL)
	{
		if (struct_di.prec != NULL)
			free(struct_di.prec);
		free(to_remplace);
		lkd_list->content = change_minus(struct_di.tmp);
	}
	else if (struct_di.prec != NULL)
	{
		free(to_remplace);
		lkd_list->content = change_minus(struct_di.prec);
	}
	else
		lkd_list->content = change_minus(to_remplace);
	return (0);
}

int			percent_di(t_word *lkd_list, va_list ap)
{
	char			*to_remplace;
	int				i;
	t_percent_di	struct_di;

	i = 0;
	struct_di.spaces = NULL;
	struct_di.prec = NULL;
	struct_di.tmp = NULL;
	to_remplace = get_option_d(ap, lkd_list);

	if (ft_strcmp(to_remplace, "0") == 0
	&& (ft_strstr(lkd_list->content, ".0")
	|| detect_prec(lkd_list->content, 0) == -1))
	{
		if (lkd_list->spaces > 0)
		{
			free(to_remplace);
			to_remplace = ft_strdup("");
		}
		else
		{
			free(lkd_list->content);
			free(to_remplace);
			lkd_list->is_malloc = 0;
			lkd_list->content = "";
			return (0);
		}
	}
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		struct_di.prec = precision(lkd_list->content, to_remplace, i, 0);

//printf("tmp = %s, to_remplace = %s, prec = %s spaces = %s\n", struct_di.tmp, to_remplace, struct_di.prec, struct_di.spaces);

//printf("+ = %d, - = %d, prec = %s\n", ft_strchr(lkd_list->content, '+'), ft_strchr(lkd_list->content, '-'), struct_di.prec);

	if (ft_strchr(lkd_list->content, '+') != -1 && ft_strchr(to_remplace, '-') != 1 && struct_di.prec)
		struct_di.tmp = ft_strjoin("+", struct_di.prec);
	else if (ft_strchr(lkd_list->content, ' ') != -1 && ft_strchr(to_remplace, '-') && struct_di.prec != NULL)
		struct_di.tmp = ft_strjoin(" ", struct_di.prec);
	else if (ft_strchr(lkd_list->content, '+') != -1 && to_remplace[0] != '-' && struct_di.prec == NULL)
		struct_di.tmp = ft_strjoin("+", to_remplace);
	else if (ft_strchr(lkd_list->content, ' ') != -1 && to_remplace[0] != '-' && struct_di.prec == NULL)
		struct_di.tmp = ft_strjoin(" ", to_remplace);

	//printf("tmp = %s, to_remplace = %s, prec = %s spaces = %s\n", struct_di.tmp, to_remplace, struct_di.prec, struct_di.spaces);

	if ((ft_isdigit(lkd_list->content[1]) ||
	lkd_list->content[1] == '-' || lkd_list->content[1] == '+')
		&& struct_di.prec == NULL && struct_di.tmp == NULL)
	{
	//	printf("Here i am\n");
		struct_di.spaces = add_space(lkd_list, to_remplace);
	}
	else if ((lkd_list->spaces > 0 || ft_strchr(lkd_list->content, '-'))
		&& struct_di.tmp != NULL)
	{
	//	printf("Here we go\n");
		struct_di.spaces = add_space(lkd_list, struct_di.tmp);
	}
	else if ((ft_isdigit(lkd_list->content[1]) || lkd_list->content[1] == '-')
		&& struct_di.prec != NULL)
	{
	//	printf("Je suis ici\n");
		struct_di.spaces = add_space(lkd_list, struct_di.prec);
	}
	//printf("tmp = %s, to_remplace = %s, prec = %s spaces = %s\n", struct_di.tmp, to_remplace, struct_di.prec, struct_di.spaces);
	return (handle_ret_di(struct_di, lkd_list, to_remplace));
}
