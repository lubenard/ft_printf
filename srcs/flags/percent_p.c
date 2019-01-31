/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:01:46 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/31 22:50:35 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** How to convert pointer address into %p ?
** Convert it in long unsigned int, then convert it in hexa
** Then add 0x before
** https://repl.it/repls/ValidBestFlashdrives
*/

int		percent_p(t_word *lkd_list, va_list ap)
{
	(void)lkd_list;
	(void)ap;
	return (0);
}
