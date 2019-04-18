/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:42:29 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/18 13:35:57 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int		main(void)
{
	printf("28) Vrai PRINTF : |%#llX| |%#llX|\n", (unsigned long long)-1, ULLONG_MAX + 1);
	ft_printf("28) Mon PRINTF  : |%#llX| |%#llX|\n", (unsigned long long)-1, ULLONG_MAX + 1);
	return (0);
}

