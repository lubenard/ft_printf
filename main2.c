/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:42:29 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/26 22:15:15 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"

int main(void)
{
	printf("vrai printf avec +d '%+d'\n", -42);
	ft_printf("mien printf avec +d '%+d'\n", -42);
	printf("vrai printf avec + d '%+ d'\n", -42);
	ft_printf("mien printf avec + d '%+ d'\n", -42);
	printf("vrai printf avec +  d '%+  d'\n", -42);
	ft_printf("mien printf avec +  d '%+  d'\n", -42);
//	printf("vrai printf '%#-08.15x'\n", 42);
//	ft_printf("my printf '%#-08.15x'\n", 42);
	return (0);
}
