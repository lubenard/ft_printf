/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:56:24 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/05 16:22:07 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		set_colors(t_word *lkd_list)
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
	return (0);
}