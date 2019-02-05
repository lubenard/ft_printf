/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:01:46 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/05 18:27:50 by lubenard         ###   ########.fr       */
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
	long unsigned int	get_value;
	char				*to_remplace;

	(void)lkd_list;
	get_value = va_arg(ap, long unsigned);
	to_remplace = convert_into_hexa(get_value);
	printf("convered into hexa = '%s'\n" ,to_remplace);
	return (0);
}
