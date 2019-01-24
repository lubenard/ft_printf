/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:40:07 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/24 14:38:06 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	printf("VRAI PRINTF:\n");
	printf("retour printf = %d\n", printf("test%d", 1536));
	printf("%d, % d\n", 1, 2);
	printf("pourcent d = %d pourcent i = %i\n", 123, 123);
	printf("%c vs %c\n", 'a', 'b');
	printf("----------------------------------\n");
	printf("MY PRINTF:\n");
	ft_printf("Test%dlol%c", 15);
	return (0);
}
