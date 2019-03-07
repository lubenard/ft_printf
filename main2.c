/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:42:29 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/07 16:32:11 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"

int main(void)
{
	int		nb;
	nb = -45;
	ft_printf("space% d\n", nb);
	ft_printf("plus:%+d\n", nb);
	ft_printf("precision:%.5d\n", nb);
	ft_printf("space + prec:% .5d\n", nb);
	ft_printf("Plus + prec / grande:%+.5d\n", nb);
	ft_printf("Plus + prec / petite:%+.0d\n", nb);
	ft_printf("Prec + 0:%0.5d\n", nb);
	ft_printf("Prec + minus:%-.5d\n", nb);
	ft_printf("size:%5d\n", nb);
	ft_printf("size + space:% 5d\n", nb);
	ft_printf("size + plus:%+5d\n", nb);
	ft_printf("size + minus:%-5d\n", nb);
	ft_printf("size + 0:%05d\n", nb);
	ft_printf("size + 0 + plus:%+05d\n", nb);
	ft_printf("size + 0 + plus:%0+5d\n", nb);
	ft_printf("size + 0 + prec:%05.3d\n", nb);
	ft_printf("size + minus + prec:%-5.3d\n", nb);
	ft_printf("size + plus + 0 + prec:%+05.3d\n", nb);

	ft_printf("space% i\n", nb);
	ft_printf("plus:%+i\n", nb);
	ft_printf("precision:%.5i\n", nb);
	ft_printf("space + prec:% .5i\n", nb);
	ft_printf("Plus + prec / grande:%+.5i\n", nb);
	ft_printf("Plus + prec / petite:%+.0i\n", nb);
	ft_printf("Prec + 0:%0.5i\n", nb);
	ft_printf("Prec + minus:%-.5i\n", nb);
	ft_printf("size:%5i\n", nb);
	ft_printf("size + space:% 5i\n", nb);
	ft_printf("size + plus:%+5i\n", nb);
	ft_printf("size + minus:%-5i\n", nb);
	ft_printf("size + 0:%05i\n", nb);
	ft_printf("size + 0 + plus:%+05i\n", nb);
	ft_printf("size + 0 + plus:%0+5i\n", nb);
	ft_printf("size + 0 + prec:%05.3i\n", nb);
	ft_printf("size + minus + prec:%-5.3i\n", nb);
	ft_printf("size + plus + 0 + prec:%+05.3i\n", nb);
	ft_printf("size + espace + zero + prec:%0 5.3i\n", nb);
	ft_printf("size + espace + zero + prec:% 05.3i\n", nb);
	ft_printf("size + minus + plus + prec:%-+5.3i\n", nb);


	return (0);
}
