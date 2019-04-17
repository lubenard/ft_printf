/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:23:03 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/17 15:42:08 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*get_option_x(va_list ap, t_word *lkd_list)
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

char	*handle_return_x(t_word *lkd_list, char *to_remplace,
	char *spaces, char *prec)
{
	free(lkd_list->content);
	free(to_remplace);
	if (spaces != NULL)
		free(spaces);
	if (prec != NULL)
		free(prec);
	return (NULL);
}

int		handle_errors_x(t_word *lkd_list, char **to_remplace)
{
	if (ft_strcmp(*to_remplace, "0") == 0 && (ft_strstr(lkd_list->content, ".0")
	|| detect_prec(lkd_list->content, 0) == -1))
	{
		free(*to_remplace);
		*to_remplace = ft_strdup("");
		if (lkd_list->spaces == 0)
		{
			free(lkd_list->content);
			free(*to_remplace);
			lkd_list->content = "";
			lkd_list->is_malloc = 0;
			return (1);
		}
	}
	return (0);
}

void	handle_errors_x2(t_word *lkd_list, char **spaces)
{
	if (ft_strchr(lkd_list->content, '#') != -1 && *spaces)
	{
		if ((*spaces)[0] == '0' && (*spaces)[1] == '0')
		{
			(*spaces)[0] = ' ';
			(*spaces)[1] = ' ';
		}
	}
}

char	*percent_x(t_word *lkd_list, va_list ap, short option)
{
	char	*to_remplace;
	int		i;
	char	*prec;
	char	*spaces;
	char	*zero_x;

	prec = NULL;
	spaces = NULL;
	to_remplace = get_option_x(ap, lkd_list);
	if (handle_errors_x(lkd_list, &to_remplace) == 1)
		return (0);
	if ((i = ft_strchr(lkd_list->content, '.')) != -1)
		prec = precision(lkd_list->content, to_remplace, i, 0);
	if ((ft_isdigit(lkd_list->content[1]) || ft_isdigit(lkd_list->content[2])
	|| lkd_list->content[1] == '-' || lkd_list->content[2] == '-')
	&& prec == NULL)
		spaces = add_space(lkd_list, to_remplace);
	else if ((ft_isdigit(lkd_list->content[1]) ||
	ft_isdigit(lkd_list->content[2]) || lkd_list->content[1] == '-'
	|| lkd_list->content[2] == '-') && prec != NULL)
		spaces = add_space(lkd_list, prec);
	handle_errors_x2(lkd_list, &spaces);
	zero_x = add_zero_x(lkd_list, to_remplace, prec, spaces);
	handle_return_x(lkd_list, to_remplace, spaces, prec);
	return (return_x(lkd_list, zero_x, option));
}
