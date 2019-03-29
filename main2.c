/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:42:29 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/29 13:36:27 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"

int main(void)
{
	/*printf("vrai printf avec +d '%+d'\n", -42);
	ft_printf("mien printf avec +d '%+d'\n", -42);
	printf("vrai printf avec + d '%+ d'\n", -42);
	ft_printf("mien printf avec + d '%+ d'\n", -42);
	printf("vrai printf avec +  d '%+  d'\n", -42);
	ft_printf("mien printf avec +  d '%+  d'\n", -42);
	printf("vrai printf avec #0x '%#0x'\n", 0);
	ft_printf("mien printf avec #0x '%#0x'\n", 0);
	printf("vrai printf avec #x '%#x'\n", 42);
	ft_printf("mien printf avec #x '%#x'\n", 42);
	printf("vrai printf avec #x '%#8x'\n", 42);
	ft_printf("mien printf avec #x '%#8x'\n", 42);
	printf("vrai printf avec 2x '%2x'\n", 542);
	ft_printf("mien printf avec 2x '%2x'\n", 542);
	printf("vrai printf avec #6o '%2o'\n", 542);
	ft_printf("mien printf avec #6o '%2o'\n", 542);
	printf("%lu\n", -42);
	ft_printf("%lu\n", -42);
	printf("vrai printf '%#-08.15x'\n", 42);
	ft_printf("my printf '%#-08.15x'\n", 42);*/

	printf("vrai printf '%#-08x'\n", 42);
	ft_printf("mien printf '%#-08x'\n", 42);
	return (0);
}
