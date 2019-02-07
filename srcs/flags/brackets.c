/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:56:24 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/07 16:50:06 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		change_fd(t_word *lkd_list, va_list ap)
{
	if (ft_strcmp(lkd_list->content, "{error}") == 0)
		lkd_list->fd = 2;
	if (ft_strcmp(lkd_list->content, "{std}") == 0)
		lkd_list->fd = 1;
	return (0);
}

int		brackets(t_word *lkd_list, va_list ap)
{
	if (ft_strcmp(lkd_list->content, "{black}") == 0)
		lkd_list->content = "\033[30m";
	else if (ft_strcmp(lkd_list->content, "{red}") == 0)
		lkd_list->content = "\033[31m";
	else if (ft_strcmp(lkd_list->content, "{green}") == 0)
		lkd_list->content = "\033[32m";
	else if (ft_strcmp(lkd_list->content, "{yellow}") == 0)
		lkd_list->content = "\033[33m";
	else if (ft_strcmp(lkd_list->content, "{blue}") == 0)
		lkd_list->content = "\033[34m";
	else if (ft_strcmp(lkd_list->content, "{purple}") == 0)
		lkd_list->content = "\033[35m";
	else if (ft_strcmp(lkd_list->content, "{cyan}") == 0)
		lkd_list->content = "\033[36m";
	else if (ft_strcmp(lkd_list->content, "{white}") == 0
	|| ft_strcmp(lkd_list->content, "{eof}") == 0)
		lkd_list->content = "\033[37m";
	else
		change_fd(lkd_list, ap);
	return (0);
}