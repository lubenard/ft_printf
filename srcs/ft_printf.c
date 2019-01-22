/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <lubenard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:38:17 by luca              #+#    #+#             */
/*   Updated: 2019/01/22 21:56:03 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *str)
{
	printf("str=%d c=%c\n", ft_strcchr(str, "%d"), str[ft_strcchr(str, "%d")]);
	ft_putstr(str);
	return (0);
}

int main(int argc, char **argv)
{
	(void) argc;
	ft_printf(argv[1]);
	return (0);
}
