/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:40:07 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/21 17:38:01 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	int test1;
	int *test2;

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
	printf("----------------------------------\n");
	printf("MY PRINTF:\n");
	printf("value = '%-15p'\n %lu\n", test2, (unsigned long)test2);
	printf("laucnching my printf\n");
	ft_printf("lol c'est %s marrant %d suce mes couilles\n", "testu", 30);
	return (0);
}
