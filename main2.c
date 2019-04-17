/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:42:29 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/17 15:19:13 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{

ft_printf("--------------------%%d-et-%%i--------------------\n");
	/*printf("01) Vrai PRINTF : |%d|\n", 42);
	ft_printf("01) Mon PRINTF  : |%d|\n", 42);
	printf("02) Vrai PRINTF : |%i|\n", 42);
	ft_printf("02) Mon PRINTF  : |%i|\n", 42);
	printf("03) Vrai PRINTF : |%+d|\n", 42);
	ft_printf("03) Mon PRINTF  : |%+d|\n", 42);
	printf("04) Vrai PRINTF : |%-d|\n", 42);
	ft_printf("04) Mon PRINTF  : |%-d|\n", 42);
	printf("05) Vrai PRINTF : |%10d|\n", 100);
	ft_printf("05) Mon PRINTF  : |%10d|\n", 100);
	printf("06) Vrai PRINTF : |%-10d|\n", 64);
	ft_printf("06) Mon PRINTF  : |%-10d|\n", 64);
	printf("07) Vrai PRINTF : |%.10d|\n", 100);
	ft_printf("07) Mon PRINTF  : |%.10d|\n", 100);
	printf("08) Vrai PRINTF : |%10.5d|\n", 100);
	ft_printf("08) Mon PRINTF  : |%10.5d|\n", 100);
	printf("09) Vrai PRINTF : |%5.10d|\n", 64);
	ft_printf("09) Mon PRINTF  : |%5.10d|\n", 64);
	printf("10) Vrai PRINTF : |%1.1d|\n", 16);
	ft_printf("10) Mon PRINTF  : |%1.1d|\n", 16);
	printf("11) Vrai PRINTF : |%+10d|\n", 50);
	ft_printf("11) Mon PRINTF  : |%+10d|\n", 50);
	printf("12) Vrai PRINTF : |%+2d|\n", 50);
	ft_printf("12) Mon PRINTF  : |%+2d|\n", 50);
	printf("13) Vrai PRINTF : |%+.10d|\n", 50);
	ft_printf("13) Mon PRINTF  : |%+.10d|\n", 50);
	printf("14) Vrai PRINTF : |%+.2d|\n", 50);
	ft_printf("14) Mon PRINTF  : |%+.2d|\n", 50);
	printf("15) Vrai PRINTF : |%          d|\n", 1);
	ft_printf("15) Mon PRINTF  : |%          d|\n", 1);
	printf("16) Vrai PRINTF : |% -d|\n", 1);
	ft_printf("16) Mon PRINTF  : |% -d|\n", 1);
	printf("17) Vrai PRINTF : |%-+d|\n", 32);
	ft_printf("17) Mon PRINTF  : |%-+d|\n", 32);
	printf("18) Vrai PRINTF : |%+-d|\n", 32);
	ft_printf("18) Mon PRINTF  : |%+-d|\n", 32);
	printf("19) Vrai PRINTF : |%-+10d|\n", 42);
	ft_printf("19) Mon PRINTF  : |%-+10d|\n", 42);
	printf("20) Vrai PRINTF : |%-+.10d|\n", 42);
	ft_printf("20) Mon PRINTF  : |%-+.10d|\n", 42);
	printf("21) Vrai PRINTF : |%d|\n", -42);
	ft_printf("21) Mon PRINTF  : |%d|\n", -42);
	printf("22) Vrai PRINTF : |%10d|\n", -42);
	ft_printf("22) Mon PRINTF  : |%10d|\n", -42);
	printf("23) Vrai PRINTF : |%.10d|\n", -42);
	ft_printf("23) Mon PRINTF  : |%.10d|\n", -42);
	printf("24) Vrai PRINTF : |%+d|\n", -10);
	ft_printf("24) Mon PRINTF  : |%+d|\n", -10);
	printf("25) Vrai PRINTF : |%10.5d|\n", -16);
	ft_printf("25) Mon PRINTF  : |%10.5d|\n", -16);
	printf("26) Vrai PRINTF : |%5.10d|\n", -16);
	ft_printf("26) Mon PRINTF  : |%5.10d|\n", -16);
	printf("27) Vrai PRINTF : |%1.1d|\n", -20);
	ft_printf("27) Mon PRINTF  : |%1.1d|\n", -20);
	printf("28) Vrai PRINTF : |%-10d|\n", -50);
	ft_printf("29) Mon PRINTF  : |%-10d|\n", -50);
	printf("30) Vrai PRINTF : |%++++++++++d|\n", 69);
	ft_printf("30) Mon PRINTF  : |%++++++++++d|\n", 69);
	printf("31) Vrai PRINTF : |%+10d|\n", -64);
	ft_printf("31) Mon PRINTF  : |%+10d|\n", -64);
	printf("32) Vrai PRINTF : |%+.10d|\n", -64);
	ft_printf("32) Mon PRINTF  : |%+.10d|\n", -64);
	printf("33) Vrai PRINTF : |%2d|\n", -20);
	ft_printf("33) Mon PRINTF  : |%2d|\n", -20);
	printf("34) Vrai PRINTF : |%.2d|\n", -20);
	ft_printf("34) Mon PRINTF  : |%.2d|\n", -20);
	printf("35) Vrai PRINTF : |%2d|\n", -1);
	ft_printf("35) Mon PRINTF  : |%2d|\n", -1);
	printf("36) Vrai PRINTF : |%.2d|\n", -1);
	ft_printf("36) Mon PRINTF  : |%.2d|\n", -1);
	printf("37) Vrai PRINTF : |%-10d|\n", -80);
	ft_printf("37) Mon PRINTF  : |%-10d|\n", -80);
	printf("38) Vrai PRINTF : |%-.10d|\n", -80);
	ft_printf("38) Mon PRINTF  : |%-.10d|\n", -80);
	printf("39) Vrai PRINTF : |%06d|\n", 35);
	ft_printf("39) Mon PRINTF  : |%06d|\n", 35);
	printf("40) Vrai PRINTF : |%06d|\n", -35);
	ft_printf("40) Mon PRINTF  : |%06d|\n", -35);
	printf("41) Vrai PRINTF : |%-+10d|\n", -40);
	ft_printf("41) Mon PRINTF  : |%-+10d|\n", -40);
	printf("42) Vrai PRINTF : |%+-10d|\n", -40);
	ft_printf("42) Mon PRINTF  : |%+-10d|\n", -40);
	printf("43) Vrai PRINTF : |%05.3d|\n", 5);
	ft_printf("43) Mon PRINTF  : |%05.3d|\n", 5);
	printf("44) Vrai PRINTF : |%03.5d|\n", 5);
	ft_printf("44) Vrai PRINTF : |%03.5d|\n", 5);
	printf("45) Vrai PRINTF : |%05.3d|\n", -5);
	ft_printf("45) Mon PRINTF  : |%05.3d|\n", -5);
	printf("46) Vrai PRINTF : |%03.5d|\n", -5);
	ft_printf("46) Mon PRINTF  : |%03.5d|\n", -5);
	printf("47) Vrai PRINTF : |%d| |%d|\n", INT_MAX, INT_MIN);
	ft_printf("47) Mon PRINTF  : |%d| |%d|\n", INT_MAX, INT_MIN);
	printf("48) Vrai PRINTF : |%d| |%d|\n", INT_MAX + 1, INT_MIN - 1);
	ft_printf("48) Vrai PRINTF : |%d| |%d|\n", INT_MAX + 1, INT_MIN - 1);
	printf("49) Vrai PRINTF : |%.d|\n", 0);
	ft_printf("49) Mon PRINTF  : |%.d|\n", 0);
	printf("50) Vrai PRINTF : |%.d|\n", 100);
	ft_printf("50) Mon PRINTF  : |%.d|\n", 100);
	ft_printf("--------------------%%o--------------------\n");
	printf("01) Vrai PRINTF : |%o|\n", 34);
	ft_printf("01) Mon PRINTF  : |%o|\n", 34);
	printf("02) Vrai PRINTF : |%o|\n", -34);
	ft_printf("02) Mon PRINTF  : |%o|\n", -34);
	printf("03) Vrai PRINTF : |%-o|\n", 50);
	ft_printf("03) Mon PRINTF  : |%-o|\n", 50);
	printf("04) Vrai PRINTF : |%10o|\n", 90);
	ft_printf("04) Mon PRINTF  : |%10o|\n", 90);
	printf("05) Vrai PRINTF : |%.10o|\n", 90);
	ft_printf("05) Mon PRINTF  : |%.10o|\n", 90);
	printf("06) Vrai PRINTF : |%15o|\n", -100);
	ft_printf("06) Mon PRINTF  : |%15o|\n", -100);
	printf("07) Vrai PRINTF : |%.15o|\n", -100);
	ft_printf("07) Mon PRINTF  : |%.15o|\n", -100);
	printf("08) Vrai PRINTF : |%10.5o|\n", 52);
	ft_printf("08) Mon PRINTF  : |%10.5o|\n", 52);
	printf("09) Vrai PRINTF : |%5.10o|\n", 52);
	ft_printf("09) Mon PRINTF  : |%5.10o|\n", 52);
	printf("10) Vrai PRINTF : |%20.15o|\n", -100000);
	ft_printf("10) Mon PRINTF  : |%20.15o|\n", -100000);
	printf("11) Vrai PRINTF : |%15.20o|\n", -100000);
	ft_printf("11) Mon PRINTF  : |%15.20o|\n", -100000);
	printf("12) Vrai PRINTF : |%-10o|\n", 144);
	ft_printf("12) Mon PRINTF  : |%-10o|\n", 144);
	printf("13) Vrai PRINTF : |%-.10o|\n", 144);
	ft_printf("13) Mon PRINTF  : |%-.10o|\n", 144);
	printf("14) Vrai PRINTF : |%-20o|\n", -20000000);
	ft_printf("14) Mon PRINTF  : |%-20o|\n", -20000000);
	printf("15) Vrai PRINTF : |%08o|\n", 64);
	ft_printf("15) Mon PRINTF  : |%08o|\n", 64);
	printf("16) Vrai PRINTF : |%03.4o|\n", 10);
	ft_printf("16) Mon PRINTF  : |%03.4o|\n", 10);
	printf("17) Vrai PRINTF : |%#o|\n", 34);
	ft_printf("17) Mon PRINTF  : |%#o|\n", 34);
	printf("18) Vrai PRINTF : |%#.5o|\n", 34);
	ft_printf("18) Mon PRINTF  : |%#.5o|\n", 34);
	printf("19) Vrai PRINTF : |%#5o|\n", 86);
	ft_printf("19) Mon PRINTF  : |%#5o|\n", 86);
	printf("20) Vrai PRINTF : |%#10.5o|\n", 70);
	ft_printf("20) Mon PRINTF  : |%#10.5o|\n", 70);
	printf("21) Vrai PRINTF : |%#o|\n", 0);
	ft_printf("21) Vrai PRINTF : |%#o|\n", 0);
	printf("22) Vrai PRINTF : |%#.o|\n", 0);
	ft_printf("22) Mon PRINTF  : |%#.o|\n", 0);
	printf("23) Vrai PRINTF : |%.o|\n", 0);
	ft_printf("23) Mon PRINTF  : |%.o|\n", 0);
	printf("24) Vrai PRINTF : |%.o|\n", 88);
	ft_printf("24) Mon PRINTF  : |%.o|\n", 88);
	printf("25) Vrai PRINTF : |%#.o|\n", 88);
	ft_printf("25) Mon PRINTF  : |%#.o|\n", 88);
	printf("26) Vrai PRINTF : |%o|\n", UINT_MAX);
	ft_printf("26) Mon PRINTF  : |%o|\n", UINT_MAX);
	printf("27) Vrai PRINTF : |%#o|\n", UINT_MAX);
	ft_printf("27) Mon PRINTF  : |%#o|\n", UINT_MAX);
	ft_printf("--------------------%%x--------------------\n");
	printf("01) Vrai PRINTF : |%x|\n", 34);
	ft_printf("01) Mon PRINTF  : |%x|\n", 34);
	printf("02) Vrai PRINTF : |%x|\n", -34);
	ft_printf("02) Mon PRINTF  : |%x|\n", -34);
	printf("03) Vrai PRINTF : |%-x|\n", 50);
	ft_printf("03) Mon PRINTF  : |%-x|\n", 50);
	printf("04) Vrai PRINTF : |%10x|\n", 90);
	ft_printf("04) Mon PRINTF  : |%10x|\n", 90);
	printf("05) Vrai PRINTF : |%.10x|\n", 90);
	ft_printf("05) Mon PRINTF  : |%.10x|\n", 90);
	printf("06) Vrai PRINTF : |%15x|\n", -100);
	ft_printf("06) Mon PRINTF  : |%15x|\n", -100);
	printf("07) Vrai PRINTF : |%.15x|\n", -100);
	ft_printf("07) Mon PRINTF  : |%.15x|\n", -100);
	printf("08) Vrai PRINTF : |%10.5x|\n", 52);
	ft_printf("08) Mon PRINTF  : |%10.5x|\n", 52);
	printf("09) Vrai PRINTF : |%5.10x|\n", 52);
	ft_printf("09) Mon PRINTF  : |%5.10x|\n", 52);
	printf("10) Vrai PRINTF : |%20.15x|\n", -100000);
	ft_printf("10) Mon PRINTF  : |%20.15x|\n", -100000);
	printf("11) Vrai PRINTF : |%15.20x|\n", -100000);
	ft_printf("11) Mon PRINTF  : |%15.20x|\n", -100000);
	printf("12) Vrai PRINTF : |%-10x|\n", 144);
	ft_printf("12) Mon PRINTF  : |%-10x|\n", 144);
	printf("13) Vrai PRINTF : |%-.10x|\n", 144);
	ft_printf("13) Mon PRINTF  : |%-.10x|\n", 144);
	printf("14) Vrai PRINTF : |%-20x|\n", -20000000);
	ft_printf("14) Mon PRINTF  : |%-20x|\n", -20000000);
	printf("15) Vrai PRINTF : |%08x|\n", 64);
	ft_printf("15) Mon PRINTF  : |%08x|\n", 64);
	printf("16) Vrai PRINTF : |%03.4x|\n", 10);
	ft_printf("16) Mon PRINTF  : |%03.4x|\n", 10);
	printf("17) Vrai PRINTF : |%#x|\n", 34);
	ft_printf("17) Mon PRINTF  : |%#x|\n", 34);
	printf("18) Vrai PRINTF : |%#.5x|\n", 34);
	ft_printf("18) Mon PRINTF  : |%#.5x|\n", 34);
	printf("19) Vrai PRINTF : |%#5x|\n", 86);
	ft_printf("19) Mon PRINTF  : |%#5x|\n", 86);
	printf("20) Vrai PRINTF : |%#10.5x|\n", 70);
	ft_printf("20) Mon PRINTF  : |%#10.5x|\n", 70);
	printf("21) Vrai PRINTF : |%#x|\n", 0);
	ft_printf("21) Vrai PRINTF : |%#x|\n", 0);
	printf("22) Vrai PRINTF : |%#.x|\n", 0);
	ft_printf("22) Mon PRINTF  : |%#.x|\n", 0);
	printf("23) Vrai PRINTF : |%.x|\n", 0);
	ft_printf("23) Mon PRINTF  : |%.x|\n", 0);
	printf("24) Vrai PRINTF : |%.x|\n", 88);
	ft_printf("24) Mon PRINTF  : |%.x|\n", 88);
	printf("25) Vrai PRINTF : |%#.x|\n", 88);
	ft_printf("25) Mon PRINTF  : |%#.x|\n", 88);
	printf("26) Vrai PRINTF : |%x|\n", UINT_MAX);
	ft_printf("26) Mon PRINT   : |%x|\n", UINT_MAX);
	printf("27) Vrai PRINTF : |%#x|\n", UINT_MAX);
	ft_printf("27) Mon PRINTF  : |%#x|\n", UINT_MAX);
	ft_printf("--------------------%%X--------------------\n");
	printf("01) Vrai PRINTF : |%X|\n", 34);
	ft_printf("01) Mon PRINTF  : |%X|\n", 34);
	printf("02) Vrai PRINTF : |%X|\n", -34);
	ft_printf("02) Mon PRINTF  : |%X|\n", -34);
	printf("03) Vrai PRINTF : |%-X|\n", 50);
	ft_printf("03) Mon PRINTF  : |%-X|\n", 50);
	printf("04) Vrai PRINTF : |%10X|\n", 90);
	ft_printf("04) Mon PRINTF  : |%10X|\n", 90);
	printf("05) Vrai PRINTF : |%.10X|\n", 90);
	ft_printf("05) Mon PRINTF  : |%.10X|\n", 90);
	printf("06) Vrai PRINTF : |%15X|\n", -100);
	ft_printf("06) Mon PRINTF  : |%15X|\n", -100);
	printf("07) Vrai PRINTF : |%.15X|\n", -100);
	ft_printf("07) Mon PRINTF  : |%.15X|\n", -100);
	printf("08) Vrai PRINTF : |%10.5X|\n", 52);
	ft_printf("08) Mon PRINTF  : |%10.5X|\n", 52);
	printf("09) Vrai PRINTF : |%5.10X|\n", 52);
	ft_printf("09) Mon PRINTF  : |%5.10X|\n", 52);
	printf("10) Vrai PRINTF : |%20.15X|\n", -100000);
	ft_printf("10) Mon PRINTF  : |%20.15X|\n", -100000);
	printf("11) Vrai PRINTF : |%15.20X|\n", -100000);
	ft_printf("11) Mon PRINTF  : |%15.20X|\n", -100000);
	printf("12) Vrai PRINTF : |%-10X|\n", 144);
	ft_printf("12) Mon PRINTF  : |%-10X|\n", 144);
	printf("13) Vrai PRINTF : |%-.10X|\n", 144);
	ft_printf("13) Mon PRINTF  : |%-.10X|\n", 144);
	printf("14) Vrai PRINTF : |%-20X|\n", -20000000);
	ft_printf("14) Mon PRINTF  : |%-20X|\n", -20000000);
	printf("15) Vrai PRINTF : |%08X|\n", 64);
	ft_printf("15) Mon PRINTF  : |%08X|\n", 64);
	printf("16) Vrai PRINTF : |%03.4X|\n", 10);
	ft_printf("16) Mon PRINTF  : |%03.4X|\n", 10);
	printf("17) Vrai PRINTF : |%#X|\n", 34);
	ft_printf("17) Mon PRINTF  : |%#X|\n", 34);
	printf("18) Vrai PRINTF : |%#.5X|\n", 34);
	ft_printf("18) Mon PRINTF  : |%#.5X|\n", 34);
	printf("19) Vrai PRINTF : |%#5X|\n", 86);
	ft_printf("19) Mon PRINTF  : |%#5X|\n", 86);
	printf("20) Vrai PRINTF : |%#10.5X|\n", 70);
	ft_printf("20) Mon PRINTF  : |%#10.5X|\n", 70);
	printf("21) Vrai PRINTF : |%#X|\n", 0);
	ft_printf("21) Vrai PRINTF : |%#X|\n", 0);
	printf("22) Vrai PRINTF : |%#.X|\n", 0);
	ft_printf("22) Mon PRINTF  : |%#.X|\n", 0);
	printf("23) Vrai PRINTF : |%.X|\n", 0);
	ft_printf("23) Mon PRINTF  : |%.X|\n", 0);
	printf("24) Vrai PRINTF : |%.X|\n", 88);
	ft_printf("24) Mon PRINTF  : |%.X|\n", 88);
	printf("25) Vrai PRINTF : |%#.X|\n", 88);
	ft_printf("25) Mon PRINTF  : |%#.X|\n", 88);
	printf("26) Vrai PRINTF : |%X|\n", UINT_MAX);
	ft_printf("26) Mon PRINT   : |%X|\n", UINT_MAX);
	printf("27) Vrai PRINTF : |%#X|\n", UINT_MAX);
	ft_printf("27) Mon PRINTF  : |%#X|\n", UINT_MAX);
	ft_printf("--------------------%%u--------------------\n");
	printf("01) Vrai PRINTF : |%u|\n", 34);
	ft_printf("01) Mon PRINTF  : |%u|\n", 34);
	printf("02) Vrai PRINTF : |%u|\n", -34);
	ft_printf("02) Mon PRINTF  : |%u|\n", -34);
	printf("03) Vrai PRINTF : |%-u|\n", 50);
	ft_printf("03) Mon PRINTF  : |%-u|\n", 50);
	printf("04) Vrai PRINTF : |%10u|\n", 90);
	ft_printf("04) Mon PRINTF  : |%10u|\n", 90);
	printf("05) Vrai PRINTF : |%.10u|\n", 90);
	ft_printf("05) Mon PRINTF  : |%.10u|\n", 90);
	printf("06) Vrai PRINTF : |%15u|\n", -100);
	ft_printf("06) Mon PRINTF  : |%15u|\n", -100);
	printf("07) Vrai PRINTF : |%.15u|\n", -100);
	ft_printf("07) Mon PRINTF  : |%.15u|\n", -100);
	printf("08) Vrai PRINTF : |%10.5u|\n", 52);
	ft_printf("08) Mon PRINTF  : |%10.5u|\n", 52);
	printf("09) Vrai PRINTF : |%5.10u|\n", 52);
	ft_printf("09) Mon PRINTF  : |%5.10u|\n", 52);
	printf("10) Vrai PRINTF : |%20.15u|\n", -100000);
	ft_printf("10) Mon PRINTF  : |%20.15u|\n", -100000);
	printf("11) Vrai PRINTF : |%15.20u|\n", -100000);
	ft_printf("11) Mon PRINTF  : |%15.20u|\n", -100000);
	printf("12) Vrai PRINTF : |%-10u|\n", 144);
	ft_printf("12) Mon PRINTF  : |%-10u|\n", 144);
	printf("13) Vrai PRINTF : |%-.10u|\n", 144);
	ft_printf("13) Mon PRINTF  : |%-.10u|\n", 144);
	printf("14) Vrai PRINTF : |%-20u|\n", -20000000);
	ft_printf("14) Mon PRINTF  : |%-20u|\n", -20000000);
	printf("15) Vrai PRINTF : |%08u|\n", 64);
	ft_printf("15) Mon PRINTF  : |%08u|\n", 64);
	printf("16) Vrai PRINTF : |%03.4u|\n", 10);
	ft_printf("16) Mon PRINTF  : |%03.4u|\n", 10);
	printf("17) Vrai PRINTF : |%.u|\n", 0);
	ft_printf("17) Mon PRINTF  : |%.u|\n", 0);
	printf("18) Vrai PRINTF : |%.u|\n", 88);
	ft_printf("18) Mon PRINTF  : |%.u|\n", 88);
	printf("19) Vrai PRINTF : |%u|\n", UINT_MAX);
ft_printf("19) Mon PRINT   : |%u|\n", UINT_MAX);*/

	// char str = 0;
	// int test1 = 1000000000;
	// int *test6 = &test1;

	// printf("--------------\n");
	// printf("|%#6o|\n", 2500);					
	// ft_printf("|%#6o|\n", 2500);

	// printf("--------------\n");
	// printf("|%#12.2o|\n", 0);					
	// ft_printf("|%#12.2o|\n", 0);
	// printf("--------------\n");
	// printf("|%#10.8o|\n", 424242);
	// ft_printf("|%#10.8o|\n", 424242);

	// printf("Vrai PRINTF : |%10c|\n", 0);
	// ft_printf("Mon PRINTF  : |%10c|\n\n", 0);

	// printf("Vrai PRINTF : |%.0c|\n", 0);
	// ft_printf("Mon PRINTF  : |%.0c|\n\n", 0);
		
	// printf("------1------\n");
	// printf("|%s|\n", "this is a string");
	// ft_printf("|%s|\n", "this is a string");
	// printf("------2-------\n");
	// printf("|%s|\n", NULL);
	// ft_printf("|%s|\n", NULL);
	// printf("------3-------\n");
	// printf("|%s|\n", "lol");
	// ft_printf("|%s|\n", "lol");
	// printf("------4-------\n");
	// printf("|%llx|\n", (long long)10);
	// ft_printf("|%llx|\n", (long long)10);
	// printf("------5-------\n");
	// printf("|%-20s| is a string\n", "this");
	// ft_printf("|%-20s| is a string\n", "this");
	// printf("------6-------\n");
	// printf("|%-2s| is a string\n", "this");
	// ft_printf("|%-2s| is a string\n", "this");
	// printf("------7-------\n");
	// 	printf("|%-.2s| is a string\n", "this");
	// ft_printf("|%-.2s| is a string\n", "this");
	// printf("------8-------\n");
	// printf("|%-5.2s| is a string\n", "this");
	// ft_printf("|%-5.2s| is a string\n", "this");
	// printf("------9-------\n");
	// printf("|%-7.7s| is a string\n", "this");
	// ft_printf("|%-7.7s| is a string\n", "this");
	// printf("-----10-------\n");
	// printf("|%-5.2s| is a string\n", "");
	// ft_printf("|%-5.2s| is a string\n", "");
	// printf("-----11-------\n");
	// printf("|%-1.0d|\n", -18);
	// ft_printf("|%-1.0d|\n", -18);
	// printf("-----12-------\n");
	// printf("|%#10o|\n", 524);
	// ft_printf("|%#10o|\n", 524);
	// printf("-----13-------\n");
	// printf("|%08x|\n", 42);
	// ft_printf("|%08x|\n", 42);
	// printf("-----14-------\n");
	// printf("|%10.08x|\n", 42);
	// ft_printf("|%10.08x|\n", 42);
	// printf("-----15-------\n");
	// printf("|%.8x|\n", 42);
	// ft_printf("|%.8x|\n", 42);
	// printf("-----16-------\n");
	// printf("|%-5.2s| is a string\n", "");
	// ft_printf("|%-5.2s| is a string\n", "");
	// printf("-----17-------\n");
	// printf("|%+d|\n", -42);
	// ft_printf("|%+d|\n", -42);
	// printf("-----18-------\n");
	// printf("|% d|\n", -42);
	// ft_printf("|% d|\n", -42);
	// printf("-----19-------\n");
	// printf("|%+5d|\n", 42);
	// ft_printf("|%+5d|\n", 42);
	// printf("-----20-------\n");
	// printf("|%+4.5d|\n", 42);
	// ft_printf("|%+4.5d|\n", 42);
	// printf("-----21-------\n");
	// printf("|%+.5d|\n", 42);
	// ft_printf("|%+.5d|\n", 42);
	// printf("-----21-------\n");
	// printf("|%05d|\n", -42);
	// ft_printf("|%05d|\n", -42);
	// printf("-----21-------\n");
	// printf("|%03.2d|\n", -1);
	// ft_printf("|%03.2d|\n", -1);
	// printf("-----22-------\n");   //   <-----------
	// printf("|%#o|\n", 42);
	// ft_printf("|%#o|\n", 42);
	// printf("-----23-------\n");
	// printf("|%#5x|\n", 42);
	// ft_printf("|%#5x|\n", 42);
	// printf("-----24-------\n");
	// printf("|%#05x|\n", 42);
	// ft_printf("|%#05x|\n", 42);
	// printf("-----24-------\n");
	// printf("|%#07x|\n", 42);
	// ft_printf("|%#07x|\n", 42);
	// printf("-----25-------\n");
	// printf("|%#.05x|\n", 42);          
	// ft_printf("|%#.05x|\n", 42);      
	// printf("-----26-------\n");
	// printf("|%#08o|\n", 42);
	// ft_printf("|%#08o|\n", 42);
	// printf("-----27-------\n");
	// printf("|%+05d|\n", 42);
	// ft_printf("|%+05d|\n", 42);  
	// printf("-----28-------\n");
	// printf("|%0+5d|\n", -42);
	// ft_printf("|%0+5d|\n", -42);
	// printf("-----29-------\n");
	// printf("|%0+5d|\n", 42);
	// ft_printf("|%0+5d|\n", 42);
	// printf("-----30-------\n");
	// printf("|%#10.05x|\n", 42);
	// ft_printf("|%#10.05x|\n", 42);
	// printf("-----31-------\n");
	// printf("|%-20.8o|\n", -42);
	// ft_printf("|%-20.8o|\n", -42);
	// printf("-----32-------\n");
	// printf("|%-20.15o|\n", -42);
	// ft_printf("|%-20.15o|\n", -42);
	// printf("-----33-------\n");
	// printf("|%-3.6o|\n", -17);
	// ft_printf("|%-3.6o|\n", -17);
	// printf("-----34-------\n");
	// printf("|%.0s|\n", "salutttt");
	// ft_printf("|%.0s|\n", "salutttt");
	// printf("-----35-------\n");
	// printf("|% %|\n");
	// ft_printf("|% %|\n");
	// printf("-----36-------\n");
	// printf("%% |%2.11u|\n", 18);
	// ft_printf("%% |%2.11u|\n", 18);
	// printf("-----37-------\n");
	// printf("|%07.5d|\n",150789);
	// ft_printf("|%07.5d|\n",150789);
	// printf("-----38-------\n");
	// printf("|%00.05d| \n", 7);
	// ft_printf("|%00.05d| \n", 7);
	// printf("-----39-------\n");
	// printf("|%05.2d|\n", 7);
	// ft_printf("|%05.2d|\n", 7);
	// printf("-----40-------\n");
	// printf("|%5%|\n");
	// ft_printf("|%5%|\n");
	// printf("-----41-------\n");
	// printf("|%.5%|\n");
	// ft_printf("|%.5%|\n");
	// printf("-----42-------\n");
	// printf("|%-.5%|\n");
	// ft_printf("|%-.5%|\n");
	// printf("-----43-------\n");
	// printf("|%8.5%|\n");
	// ft_printf("|%8.5%|\n");
	// printf("-----44-------\n");
	// printf("|%+8.5%|\n");
	// ft_printf("|%+8.5%|\n");
	// printf("-----45-------\n");
	// printf("|%-5%|\n");
	// ft_printf("|%-5%|\n");
	// printf("-----46-------\n");
	// printf("|%-8.5%|\n");
	// ft_printf("|%-8.5%|\n");
	// printf("-----46-------\n");
	// printf("|%+-8.5%|\n");
	// ft_printf("|%+-8.5%|\n");
	// printf("-----47-------\n");
	// printf("|%-8.5%|\n");
	// ft_printf("|%-8.5%|\n");
	// printf("-----48-------\n");
	// printf("|%5.2s| is a string\n", "this");
	// ft_printf("|%5.2s| is a string\n", "this");
	// printf("-----49-------\n");
	// printf("|%12s| is a string\n", "this");
	// ft_printf("|%12s| is a string\n", "this");
	// printf("-----50-------\n");
	// printf("|%#.x| |%#.0x|\n", 0, 0);
	// ft_printf("|%#.x| |%#.0x|\n", 0, 0);
	// printf("-----51-------\n");
	// printf("|%5.x| |%5.0x|\n", 0, 0);
	// ft_printf("|%5.x| |%5.0x|\n", 0, 0);
	// printf("--------------\n");
	// printf("-----52-------\n");
	// printf("|%.x| |%.0x|\n", 0, 0);
	// ft_printf("|%.x| |%.0x|\n", 0, 0);

	// printf("vrai printf avec +d '%+d'\n", -42);
	// ft_printf("mien printf avec +d '%+d'\n", -42);

	// printf("vrai printf avec + d '%+ d'\n", -42);
	// ft_printf("mien printf avec + d '%+ d'\n", -42);

	// printf("vrai printf avec +  d '%+  d'\n", -42);
	// ft_printf("mien printf avec +  d '%+  d'\n", -42);

	// printf("vrai printf avec #0x '%#0x'\n", 0);
	// ft_printf("mien printf avec #0x '%#0x'\n", 0);

	// printf("vrai printf avec 0x '%0x'\n", 0);
	// ft_printf("mien printf avec 0x '%0x'\n", 0);

	// printf("vrai printf avec #x '%#x'\n", 42);
	// ft_printf("mien printf avec #x '%#x'\n", 42);

	// printf("vrai printf avec #x '%#8x'\n", 42);
	// ft_printf("mien printf avec #x '%#8x'\n", 42);

	// printf("vrai printf avec 2x '%2x'\n", 542);
	// ft_printf("mien printf avec 2x '%2x'\n", 542);

	// printf("vrai printf avec #6o '%2o'\n", 542);
	// ft_printf("mien printf avec #6o '%2o'\n", 542);

	// printf("vrai printf avec lu '%lu'\n", -42);
	// ft_printf("mien printf avec lu '%lu'\n", -42);

	// printf("vrai printf avec -#08.15x '%#-08.15x'\n", 42);
	// ft_printf("mien printf avec -#08.15x '%#-08.15x'\n", 42);

	// printf("vrai printf avec #-08x '%#-08x'\n", 42);
	// ft_printf("mien printf avec #-08x '%#-08x'\n", 42);

	// printf("'@moulitest: '%#.x' '%#.0x''\n", 0, 0);
	// ft_printf("'@moulitest: '%#.x' '%#.0x''\n", 0, 0);
	
	// printf("vrai printf avec lu '%lu'\n", -42);
	// ft_printf("mien printf avec lu '%lu'\n", -42);
	
	// printf("vrai printf avec .0o '%.0o'\n", 0);
	// ft_printf("mien printf avec .0o '%.0o'\n", 0);

	// printf("vrai printf avec lld '%lld'\n", (long long)LLONG_MIN);
	// ft_printf("mien printf avec lld '%lld'\n", (long long)LLONG_MIN);
	
	// printf("vrai printf avec #6o '%#6o'\n", 2500);
	// ft_printf("mien printf avec #6o '%#6o'\n", 2500);
	
	// printf("vrai printf avec -#6o '%-#6o'\n", 2500);
	// ft_printf("mien printf avec -#6o '%-#6o'\n", 2500);
	
	// printf("vrai printf avec -.2s '%-.2s'\n", "");
	// ft_printf("mien printf avec -.2s '%-.2s'\n", "");

	// printf("vrai printf avec ho '%ho'\n", (short)-127);
 //    ft_printf("mien printf avec ho '%ho'\n", (short)-127);

 //    printf("%lu\n", (long)-42);
	// ft_printf("%lu\n", (long)-42);

	// printf("|%c|\n",0);
	// ft_printf("|%c|\n",0);

	// printf("Vrai: '%5.d' '%5.0d'\n", 0, 0);
	// ft_printf("Mien: '%5.d' '%5.0d'\n", 0, 0);

	// printf("vrai: '%5.o' '%5.0o'\n", 0, 0);
	// ft_printf("mien: '%5.o' '%5.0o'\n", 0, 0);

	// printf("vrai: '%03.2d'\n", 1);
	//  ft_printf("mien: '%03.2d'\n", 1);

	// printf("@moulitest: %.5u\n", 42);
	// ft_printf("@moulitest: %.5u\n", 42);

	// printf("-----21-------\n");
	// printf("|%00.3d|\n", -12);
	// ft_printf("|%00.3d|\n", -12);
	// printf("-----21-------\n");
	// printf("|%10.5d|\n", -1);
	// ft_printf("|%10.5d|\n", -1);

	// printf("|%.0s|\n",str);
	// ft_printf("|%.0s|\n\n",str);
	
	// printf("|%55.0s|\n",NULL);
	// ft_printf("|%55.0s|\n\n",NULL);
	
	// printf("|%-55.10s|\n",NULL);
	// ft_printf("|%-55.10s|\n\n",NULL);
	
	// printf("|%55.10s|\n",NULL);
	// ft_printf("|%55.10s|\n\n",NULL);

	// printf("|%#.8x|\n",42424242);
	// ft_printf("|%#.8x|\n\n",42424242);

	return (0);
}
