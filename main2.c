/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:42:29 by lubenard          #+#    #+#             */
/*   Updated: 2019/04/12 17:03:23 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <limits.h>

int main(void)
{

	/*printf("------1------\n");
	printf("|%s|\n", "this is a string");
	ft_printf("|%s|\n", "this is a string");
	printf("------2-------\n");
	printf("|%s|\n", NULL);
	ft_printf("|%s|\n", NULL);
	printf("------3-------\n");
	printf("|%s|\n", "lol");
	ft_printf("|%s|\n", "lol");
	printf("------4-------\n");
	printf("|%llx|\n", (long long)10);
	ft_printf("|%llx|\n", (long long)10);
	printf("------5-------\n");
	printf("|%-20s| is a string\n", "this");
	ft_printf("|%-20s| is a string\n", "this");
	printf("------6-------\n");
	printf("|%-2s| is a string\n", "this");
	ft_printf("|%-2s| is a string\n", "this");
	printf("------7-------\n");
	printf("|%-.2s| is a string\n", "this");
	ft_printf("|%-.2s| is a string\n", "this");
	printf("------8-------\n");
	printf("|%-5.2s| is a string\n", "this");
	ft_printf("|%-5.2s| is a string\n", "this");
	printf("------9-------\n");
	printf("|%-7.7s| is a string\n", "this");
	ft_printf("|%-7.7s| is a string\n", "this");
	printf("-----10-------\n");
	printf("|%-5.2s| is a string\n", "");
	ft_printf("|%-5.2s| is a string\n", "");
	printf("-----11-------\n");
	printf("|%-1.0d|\n", -18);
	ft_printf("|%-1.0d|\n", -18);
	printf("-----12-------\n");
	printf("|%#10o|\n", 524);
	ft_printf("|%#10o|\n", 524);
	printf("-----13-------\n");
	printf("|%08x|\n", 42);
	ft_printf("|%08x|\n", 42);
	printf("-----14-------\n");
	printf("|%10.08x|\n", 42);
	ft_printf("|%10.08x|\n", 42);
	printf("-----15-------\n");
	printf("|%.8x|\n", 42);
	ft_printf("|%.8x|\n", 42);
	printf("-----16-------\n");
	printf("|%-5.2s| is a string\n", "");
	ft_printf("|%-5.2s| is a string\n", "");
	printf("-----17-------\n");
	printf("|%+d|\n", -42);
	ft_printf("|%+d|\n", -42);
	printf("-----18-------\n");
	printf("|% d|\n", -42);
	ft_printf("|% d|\n", -42);
	printf("-----19-------\n");
	printf("|%+5d|\n", 42);
	ft_printf("|%+5d|\n", 42);
	printf("-----20-------\n");
	printf("|%+4.5d|\n", 42);
	ft_printf("|%+4.5d|\n", 42);
	printf("-----21-------\n");
	printf("|%+.5d|\n", 42);
	ft_printf("|%+.5d|\n", 42);
	printf("-----21-------\n");
	printf("|%05d|\n", -42);
	ft_printf("|%05d|\n", -42);
	printf("-----21-------\n");
	printf("|%03.2d|\n", -1);
	ft_printf("|%03.2d|\n", -1);
	printf("-----22-------\n");
	printf("|%#o|\n", 42);
	ft_printf("|%#o|\n", 42);
	printf("-----23-------\n");
	printf("|%#5x|\n", 42);
	ft_printf("|%#5x|\n", 42);
	printf("-----24-------\n");
	printf("|%#05x|\n", 42);
	ft_printf("|%#05x|\n", 42);
	printf("-----24-------\n");
	printf("|%#07x|\n", 42);
	ft_printf("|%#07x|\n", 42);
	printf("-----25-------\n");
	printf("|%#.05x|\n", 42);          
	ft_printf("|%#.05x|\n", 42);      //   <--------
	printf("-----26-------\n");
	printf("|%#08o|\n", 42);
	ft_printf("|%#08o|\n", 42);
	printf("-----27-------\n");
	printf("|%+05d|\n", 42);
	ft_printf("|%+05d|\n", 42);  
	printf("-----28-------\n");
	printf("|%0+5d|\n", -42);
	ft_printf("|%0+5d|\n", -42);
	printf("-----29-------\n");
	printf("|%0+5d|\n", 42);
	ft_printf("|%0+5d|\n", 42);
	printf("-----30-------\n");
	printf("|%#10.05x|\n", 42);
	ft_printf("|%#10.05x|\n", 42);
	printf("-----31-------\n");
	printf("|%-20.8o|\n", -42);
	ft_printf("|%-20.8o|\n", -42);
	printf("-----32-------\n");
	printf("|%-20.15o|\n", -42);
	ft_printf("|%-20.15o|\n", -42);
	printf("-----33-------\n");
	printf("|%-3.6o|\n", -17);
	ft_printf("|%-3.6o|\n", -17);
	printf("-----34-------\n");
	printf("|%.0s|\n", "salutttt");
	ft_printf("|%.0s|\n", "salutttt");
	printf("-----35-------\n");
	printf("|% %|\n");
	ft_printf("|% %|\n");
	printf("-----36-------\n");
	printf("%% |%2.11u|\n", 18);
	ft_printf("%% |%2.11u|\n", 18);*/
	printf("-----37-------\n");
	printf("|%07.5d|,|%d|\n",150789, 17);   //   <-----------
	ft_printf("|%07.5d|,|%d|\n",150789, 17);
	/*printf("-----38-------\n");
	printf("|%00.05d| \n", 7);
	ft_printf("|%00.05d| \n", 7);*/
	printf("-----39-------\n");
	printf("|%05.2d|\n", 7);     //     <------------
	ft_printf("|%05.2d|\n", 7);
	/*printf("-----40-------\n");
	printf("|%5%|\n");
	ft_printf("|%5%|\n");
	printf("-----41-------\n");
	printf("|%.5%|\n");
	ft_printf("|%.5%|\n");
	printf("-----42-------\n");
	printf("|%-.5%|\n");
	ft_printf("|%-.5%|\n");
	printf("-----43-------\n");
	printf("|%8.5%|\n");
	ft_printf("|%8.5%|\n");
	printf("-----44-------\n");
	printf("|%+8.5%|\n");
	ft_printf("|%+8.5%|\n");
	printf("-----45-------\n");
	printf("|%-5%|\n");
	ft_printf("|%-5%|\n");
	printf("-----46-------\n");
	printf("|%-8.5%|\n");
	ft_printf("|%-8.5%|\n");
	printf("-----46-------\n");
	printf("|%+-8.5%|\n");
	ft_printf("|%+-8.5%|\n");
	printf("-----47-------\n");
	printf("|%-8.5%|\n");
	ft_printf("|%-8.5%|\n");
	printf("-----48-------\n");
	printf("|%5.2s| is a string\n", "this");
	ft_printf("|%5.2s| is a string\n", "this");
	printf("-----49-------\n");
	printf("|%12s| is a string\n", "this");
	ft_printf("|%12s| is a string\n", "this");
	printf("-----50-------\n");
	printf("|%#.x| |%#.0x|\n", 0, 0);
	ft_printf("|%#.x| |%#.0x|\n", 0, 0);
	printf("-----51-------\n");
	printf("|%5.x| |%5.0x|\n", 0, 0);
	ft_printf("|%5.x| |%5.0x|\n", 0, 0);
	printf("--------------\n");
	printf("-----52-------\n");
	printf("|%.x| |%.0x|\n", 0, 0);
	ft_printf("|%.x| |%.0x|\n", 0, 0);

	printf("vrai printf avec +d '%+d'\n", -42);
	ft_printf("mien printf avec +d '%+d'\n", -42);

	printf("vrai printf avec + d '%+ d'\n", -42);
	ft_printf("mien printf avec + d '%+ d'\n", -42);

	printf("vrai printf avec +  d '%+  d'\n", -42);
	ft_printf("mien printf avec +  d '%+  d'\n", -42);

	printf("vrai printf avec #0x '%#0x'\n", 0);
	ft_printf("mien printf avec #0x '%#0x'\n", 0);

	printf("vrai printf avec 0x '%0x'\n", 0);
	ft_printf("mien printf avec 0x '%0x'\n", 0);

	printf("vrai printf avec #x '%#x'\n", 42);
	ft_printf("mien printf avec #x '%#x'\n", 42);

	printf("vrai printf avec #x '%#8x'\n", 42);
	ft_printf("mien printf avec #x '%#8x'\n", 42);

	printf("vrai printf avec 2x '%2x'\n", 542);
	ft_printf("mien printf avec 2x '%2x'\n", 542);

	printf("vrai printf avec #6o '%2o'\n", 542);
	ft_printf("mien printf avec #6o '%2o'\n", 542);

	printf("vrai printf avec lu '%lu'\n", -42);
	ft_printf("mien printf avec lu '%lu'\n", -42);

	printf("vrai printf avec -#08.15x '%#-08.15x'\n", 42);       //<----------------------------------
	ft_printf("mien printf avec -#08.15x '%#-08.15x'\n", 42);

	printf("vrai printf avec #-08x '%#-08x'\n", 42);
	ft_printf("mien printf avec #-08x '%#-08x'\n", 42);

	printf("'@moulitest: '%#.x' '%#.0x''\n", 0, 0);
	ft_printf("'@moulitest: '%#.x' '%#.0x''\n", 0, 0);
	
	printf("vrai printf avec lu '%lu'\n", -42);
	ft_printf("mien printf avec lu '%lu'\n", -42);
	
	printf("vrai printf avec .0o '%.0o'\n", 0);
	ft_printf("mien printf avec .0o '%.0o'\n", 0);

	printf("vrai printf avec lld '%lld'\n", (long long)LLONG_MIN);
	ft_printf("mien printf avec lld '%lld'\n", (long long)LLONG_MIN);
	
	printf("vrai printf avec #6o '%#6o'\n", 2500);
	ft_printf("mien printf avec #6o '%#6o'\n", 2500);
	
	printf("vrai printf avec -#6o '%-#6o'\n", 2500);
	ft_printf("mien printf avec -#6o '%-#6o'\n", 2500);
	
	printf("vrai printf avec -.2s '%-.2s'\n", "");
	ft_printf("mien printf avec -.2s '%-.2s'\n", "");

	printf("vrai printf avec ho '%ho'\n", (short)-127);
    ft_printf("mien printf avec ho '%ho'\n", (short)-127);

    printf("%lu\n", (long)-42);
	ft_printf("%lu\n", (long)-42);

	printf("|%c|\n",0);
	ft_printf("|%c|\n",0);

	printf("Vrai: '%5.d' '%5.0d'\n", 0, 0);
	ft_printf("Mien: '%5.d' '%5.0d'\n", 0, 0);

	printf("vrai: '%5.o' '%5.0o'\n", 0, 0);
	ft_printf("mien: '%5.o' '%5.0o'\n", 0, 0);

	printf("vrai: '%03.2d'\n", 1);
	 ft_printf("mien: '%03.2d'\n", 1);


	ft_printf("@moulitest: %.5u", 42);
	printf("%hu, %hu\n", 0, USHRT_MAX);
	ft_printf("%hu, %hu\n", 0, USHRT_MAX);*/

	return (0);
}
