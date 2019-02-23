/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:40:07 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/23 11:10:16 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"

int main(void)
{
	int test1;
	int *test2;
	char test3;

	test3 = 10;
	test1 = 120011;
	test2 = &test1;
	printf("VRAI PRINTF:\n");
	printf("retour printf = %d\n", printf("test%d", 1536));
	printf("%d, % d\n", 1, 2);
	printf("pourcent d = %d pourcent i = %i\n", 123, 123);
	printf("%c vs %20c\n", 'a', 'b');
	printf("%10s:\n", "help pls");
	printf("'%-20s'\n","Yo les copains");
	printf("'EUUHHHH = %x'\n", test1);
	printf("%x\n", 'c');
	printf("%u\n", -1);
	printf("%hhd\n", test3);
	printf("----------------------------------\n");
	printf("MY PRINTF:\n");
	ft_printf("%o\n", 1000);
	ft_printf("%hhd\n", test3);
	ft_printf("%hhd\n", test3);
//	ft_dprintf(2, "%hhd\n", 42); //A regler
	return (0);
}
