/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:40:07 by lubenard          #+#    #+#             */
/*   Updated: 2019/02/25 21:01:42 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"

int main(void)
{
	int test1 = 1000000000;
	short int test2 = 10000;
	char test3 = 42;
	long int test4 = 4000000000;
	long long int test5 = 8000000000;
	int *test6 = &test1;

	printf("VRAI PRINTF:\n");
	printf("test printf\n");
	printf("%c\n", 'k');
	printf("%s\n", "POULOULOU");
	printf("%p\n", test6);
	printf("%d\n", test1);
	printf("%i", test1);
	printf("%hd\n", test2);
	printf("%hi\n", test2);
	printf("%hhd\n", test3);
	printf("%hhi\n", test3);
	printf("%ld\n", test4);
	printf("%li\n",test4);
	printf("%lld\n", test5);
	printf("%lli\n", test5);
	printf("%o\n", 1000);
	printf("%o\n", 0x1000);
	printf("%u\n", 1000);
//	printf("%u\n", 4294967295);
	printf("%u\n", -1);
	printf("%u\n", -100);
	printf("%hu\n", 1100);
	printf("----------------------------------\n");
	printf("MY PRINTF:\n");
	ft_printf("test printf\n");
	ft_printf("%c\n", 'k');
	ft_printf("%s\n", "POULOULOU");
	ft_printf("%p\n", test6);
	ft_printf("%d\n", test1);
	ft_printf("%i\n", test1);
	ft_printf("%hd\n", test2);
	ft_printf("%hi\n", test2);
	ft_printf("%hhd\n", test3);
	ft_printf("%hhi\n", test3);
	ft_printf("%ld\n", test4);
	ft_printf("%li\n",test4);
	ft_printf("%lld\n", test5);
	ft_printf("%lli\n", test5);
	ft_printf("%o\n", 1000);
	ft_printf("%o\n", 0x1000);
	ft_printf("%u\n", 1000);
//	ft_printf("%u\n", 4294967295);
	ft_printf("%u\n", -1);
	ft_printf("%u\n", -100);
	return (0);
}
