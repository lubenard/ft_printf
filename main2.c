/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:42:29 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/07 06:19:26 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"

int main(void)
{
	//printf("'%.13x'\n", 1000);
	//ft_printf("'%.13x'\n", 1000);
	//printf("'%.13s'\n", "HIHI");
//	ft_printf("'%.13s'\n", "HIHI");
//	printf("'%.2s'\n", "HIHI");
//	ft_printf("'%.2s'\n", "HIHI");
//	ft_printf("Pourcent s: '%10s'\n", "hihihi");
	printf("'%010d'\n", 1000);
	printf("'%010d'\n", -1000);

	ft_printf("'%010d'\n", 1000);
	ft_printf("'%010d'\n", -1000);
	return (0);
}
