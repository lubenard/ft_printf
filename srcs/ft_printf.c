/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:38:17 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/23 07:59:59 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			ret;

	ret = 0;
	va_start(ap, str); // stdarg pour avoir des arguments a l'infinie
	ret = parsing(str, ap, 1);
	va_end(ap);
	return (ret);
}

int		ft_dprintf(int fd, const char *str, ...)
{
	va_list		ap;
	int			ret;

	ret = 0;
	va_start(ap, str);
	ret = parsing(str, ap, fd);
	va_end(ap);
	return (ret);
}
