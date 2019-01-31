/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:40:07 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/31 11:47:36 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	int test1;
	void *test2;

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
	printf("----------------------------------\n");
	printf("MY PRINTF:\n");
	ft_printf("Test%-20sPtdr%20c%x%%","Yo les copains", 'c', 1000, 152);
	return (0);
}
