/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <lubenard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:38:17 by luca              #+#    #+#             */
/*   Updated: 2019/02/08 11:20:58 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
//	char		*tab[] = {"{red}", "%.100x", "{white}", "%110.100p", "%o", "%X",  "\0"};

	va_start(ap, str); // stdarg pour avoir des arguments a l'infinie
	parsing((char*)str, ap);
	//scanning(str);
	return (0);
}
