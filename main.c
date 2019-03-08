/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:40:07 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/08 17:55:46 by lubenard         ###   ########.fr       */
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
	unsigned short test7 = 100;
	unsigned long test8 = 4000000000;
	unsigned long long test9 = 8000000000;
	unsigned int test10 = 4294967295;
	char *test11 = NULL;
	char *test12 = 0x0;
	int test13 = INT_MAX;

/*	printf("VRAI PRINTF:\n");
	printf("-----Test normaux-----\n");
	printf("test printf\n");
//	printf("\0");
	printf("");
	printf("-----Test %%c-----\n");
	printf("%c\n", 'k');
	printf("%c\n", '\n');
	printf("%c\n", '\0');
	printf("test avec 0 : '%c'\n", 0);
	printf("-----Test %%s-----\n");
	printf("%s\n", "POULOULOU");
	printf("%s\n", "\0");
	printf("%s", "JURE LE YA UN RETOUR LIGNE\n");
	printf("-----Test %%p-----\n");
	printf("%p\n", test6);
	printf("%p\n", test11);
	printf("%p\n", test12);
	printf("-----Test %%%%-----\n");
	printf("%%\n");
	printf("-----Test %%d et %%i-----\n");
	printf("%d\n", test1);
	printf("%i\n", test1);
	printf("%d\n", test13);
	printf("%hd\n", test2);
	printf("%hi\n", test2);
	printf("%hhd\n", test3);
	printf("%hhi\n", test3);
	printf("%ld\n", test4);
	printf("%li\n",test4);
	printf("%lld\n", test5);
	printf("%lli\n", test5);
	printf("-----Test %%o-----\n");
	printf("%o\n", 1000);
	printf("%o\n", 0x1000);
	printf("%ho\n", test7);
	printf("%hho\n", test3);
	printf("%lo\n", test8);
	printf("%llo\n", test9);
	printf("-----Test %%u-----\n");
	printf("%u\n", 1000);
	printf("%u\n", test10);
	printf("%u\n", -1);
	printf("%u\n", -100);
	printf("%hu\n", test7);
	printf("%hhu\n", test3);
	printf("%lu\n", test8);
	printf("%llu\n", test9);
	printf("-----Test %%x et %%X-----\n");
	printf("%x\n", 1000);
	printf("%hx\n", test7);
	printf("%hhx\n", test3);
	printf("%lx\n", test8);
	printf("%llx\n", test9);
	printf("%X\n", 1000);
	printf("%hX\n", test7);
	printf("%hhX", test3);
	printf("%lX\n", test8);
	printf("%llX\n", test9);
	printf("-----Test Minwidth-----\n");
	printf("Pourcent c: '%10c'\n", 'o');
	printf("Pourcent c: '%-10c'\n", 'o');
	printf("Pourcent s: '%10s'\n", "hihihi");
	printf("Pourcent s: '%-10s'\n", "hihihi");
	printf("Pourcent s: '%10s'\n", "hohohohohohohoho");
	printf("Pourcent s: '%-10s'\n", "hohohohohohohoho");
	printf("Pourcent p: '%20p'\n", test6);
	printf("Pourcent p: '%-20p'\n", test6);
	printf("Pourcent di: '%10d'\n", 42);
	printf("Pourcent di: '%-10d'\n", 42);
	printf("Pourcent di: '%10d'\n", -1000);
	printf("Pourcent di: '%-10d'\n", -1000);
	printf("Pourcent o: '%10o' \n", 1000);
	printf("Pourcent o: '%-10o'\n", 1000);
	printf("Pourcent u: '%10u'\n", 100);
	printf("Pourcent u: '%-10u'\n", 100);
	printf("Pourcent x: '%10x'\n", 1000);
	printf("Pourcent X: '%10X'\n", 1000);
	printf("Pourcent X: '%-10X'\n", 1000);
	printf("Pourcent pourcent : '%10%'\n");
	printf("Pourcent pourcent : '%-10%'\n");
	printf("-----Test precision-----\n");
//	printf("Pourcent c: '%.10c'\n", 'o');
	printf("Pourcent s: '%.10s'\n", "hohohohohohohoho");
//	printf("Pourcent p: '%.20p'\n", test6);
	printf("Pourcent di: '%.10d'\n", 42);
	printf("Pourcent o: '%.10o' \n", 1000);
	printf("Pourcent u: '%.10u'\n", 100);
	printf("Pourcent x: '%.10x'\n", 1000);
	printf("Pourcent X: '%.10X'\n", 1000);
	printf("Pourcent pourcent : '%.10%'\n");
	printf("-----Test +- #0-----\n");
	printf("D:\n");
	printf("espace positif '% d'\n", 1000);
	printf("espace negatif '% d'\n", -1000);
	printf("plus positif '%+d'\n", 1000);
	printf("plus negatif '%+d'\n", -1000);
	printf("moins positif '%-10d'\n", 1000);
	printf("moins negatif '%-10d'\n", -1000);
	printf("zero positif '%010d'\n", 1000);
	printf("zero negatif '%010d'\n", -1000);
	printf("zero negatif '%010.06d'\n", -1000);
	printf("----------------------------------\n");*/
	ft_printf("MY PRINTF:\n");
	ft_printf("-----Test normaux-----\n");
	ft_printf("test printf\n");
	ft_printf("\0");
	ft_printf("");
	ft_printf("-----Test %%c-----\n");
	ft_printf("%c\n", 'k');
	ft_printf("%c\n", '\n');
	ft_printf("%c\n", '\0');
	ft_printf("test avec 0 '%c'\n", 0);
	ft_printf("-----Test %%s-----\n");
	ft_printf("%s\n", "POULOULOU");
	ft_printf("%s\n", "\0");
	ft_printf("%s", "JURE LE YA UN RETOUR LIGNE\n");
	ft_printf("-----Test %%p-----\n");
	ft_printf("%p\n", test6);
	ft_printf("%p\n", test11);
	ft_printf("%p\n", test12);
	ft_printf("-----Test %%%%-----\n");
	ft_printf("%%\n");
	ft_printf("-----Test %%d et %%i-----\n");
	ft_printf("%d\n", test1);
	ft_printf("%i\n", test1);
	ft_printf("%d\n", test13);
	ft_printf("%hd\n", test2);
	ft_printf("%hi\n", test2);
	ft_printf("%hhd\n", test3);
	ft_printf("%hhi\n", test3);
	ft_printf("%ld\n", test4);
	ft_printf("%li\n",test4);
	ft_printf("%lld\n", test5);
	ft_printf("%lli\n", test5);
	ft_printf("-----Test %%o-----\n");
	ft_printf("%o\n", 1000);
	ft_printf("%o\n", 0x1000);
	ft_printf("%ho\n", test7);
	ft_printf("%hho\n", test3);
	ft_printf("%lo\n", test8);
	ft_printf("%llo\n", test9);
	ft_printf("-----Test %%u-----\n");
	ft_printf("%u\n", 1000);
	ft_printf("%u\n", test10);
	ft_printf("%u\n", -1);
	ft_printf("%u\n", -100);
	ft_printf("%hu\n", test7);
	ft_printf("%hhu\n", test3);
	ft_printf("%lu\n", test8);
	ft_printf("%llu\n", test9);
	ft_printf("-----Test %%x et %%X-----\n");
	ft_printf("%x\n", 1000);
	ft_printf("%hx\n", test7);
	ft_printf("%hhx\n", test3);
	ft_printf("%lx\n", test8);
	ft_printf("%llx\n", test9);
	ft_printf("%X\n", 1000);
	ft_printf("%hX\n", test7);
	ft_printf("%hhX", test3);
	ft_printf("%lX\n", test8);
	ft_printf("%llX\n", test9);
	/*ft_printf("-----Test Minwidth-----\n");
	ft_printf("Pourcent c: '%10c'\n", 'o');
	ft_printf("Pourcent c: '%-10c'\n", 'o');
	ft_printf("Pourcent s: '%10s'\n", "hihihi");
	ft_printf("Pourcent s: '%-10s'\n", "hihihi");
	ft_printf("Pourcent s: '%10s'\n", "hohohohohohohoho");
	ft_printf("Pourcent s: '%-10s'\n", "hohohohohohohoho");
	ft_printf("Pourcent p: '%20p'\n", test6);
	ft_printf("Pourcent p: '%-20p'\n", test6);
	ft_printf("Pourcent di: '%10d'\n", 42);
	ft_printf("Pourcent di: '%-10d'\n", 42);
	ft_printf("Pourcent o: '%10o' \n", 1000);
	ft_printf("Pourcent o: '%-10o'\n", 1000);
	ft_printf("Pourcent u: '%10u'\n", 100);
	ft_printf("Pourcent u: '%-10u'\n", 100);
	ft_printf("Pourcent x: '%10x'\n", 1000);
	ft_printf("Pourcent X: '%10X'\n", 1000);
	ft_printf("Pourcent X: '%-10X'\n", 1000);
	ft_printf("Pourcent pourcent : '%10%'\n");
	ft_printf("Pourcent pourcent : '%-10%'\n");
	ft_printf("-----Test precision-----\n");
//	ft_printf("Pourcent c: '%.10c'\n", 'o');
	ft_printf("Pourcent s: '%.10s'\n", "hohohohohohohoho");
//	ft_printf("Pourcent p: '%.20p'\n", test6);
	ft_printf("Pourcent d: '%.10d'\n", 42);
	ft_printf("Pourcent o: '%.10o' \n", 1000);
	ft_printf("Pourcent u: '%.10u'\n", 100);
	ft_printf("Pourcent x: '%.10x'\n", 1000);
	ft_printf("Pourcent X: '%.10X'\n", 1000);
	ft_printf("Pourcent pourcent : '%.10%'\n");
	ft_printf("-----Test +- #0-----\n");
	ft_printf("D:\n");
	ft_printf("espace positif '% d'\n", 1000);
	ft_printf("espace negatif '% d'\n", -1000);
	ft_printf("plus positif '%+d'\n", 1000);
	ft_printf("plus negatif '%+d'\n", -1000);
	ft_printf("moins positif '%-10d'\n", 1000);
	ft_printf("moins negatif '%-10d'\n", -1000);
	ft_printf("zero positif '%010d'\n", 1000);
	ft_printf("zero negatif '%010d'\n", -1000);
	ft_printf("zero negatif '%-010d'\n", -1000);
	ft_printf("zero negatif '%10.06d'\n", -1000);
	printf("VALEURS DE RETOUR de \\0 = %d\n", printf("%c", '\0'));

	printf("VALEURS DE RETOUR de \\0 = %d\n", ft_printf("%c", '\0'));
*/
	return (0);
}
