/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <lubenard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:38:17 by luca              #+#    #+#             */
/*   Updated: 2019/02/06 18:05:04 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	char		*tab[] = {"{red}", "%.100x", "{white}", "%110.100p", "%o", "%X",  "\0"};

	va_start(ap, str); // stdarg pour avoir des arguments a l'infinie
	//ft_putstr(ft_itoa(va_arg(ap, int))); //afficher un int par exemple
	parsing(tab, ap);
	//scanning(str);
	return (0);
}
