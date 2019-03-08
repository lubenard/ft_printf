/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:42:29 by lubenard          #+#    #+#             */
/*   Updated: 2019/03/08 17:02:21 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"

int main(void)
{
	int		nb;
	nb = -45;
	char *str;
	str  = "Okalm";
	/*printf("space% d\n", nb);
	printf("plus:%+d\n", nb);
	printf("precision:%.5d\n", nb);
	printf("space + prec:% .5d\n", nb);
	printf("Plus + prec / grande:%+.5d\n", nb);
	printf("Plus + prec / petite:%+.0d\n", nb);
	printf("Prec + 0:%0.5d\n", nb);
	printf("Prec + minus:%-.5d\n", nb);
	printf("size:'%5d'\n", nb);
	printf("size + space:'% 5d'\n", nb);
	printf("size + plus:'%+5d'\n", nb);
	printf("size + minus:'%-5d'\n", nb);*/
	printf("size + 0:'%05d'\n", nb);
	printf("size + 0 + plus:'%+05d'\n", nb);
	printf("size + 0 + plus:'%0+5d'\n", nb);
	printf("size + 0 + prec:'%05.3d'\n", nb);
	printf("size + minus + prec:'%-5.3d'\n", nb);
	printf("size + plus + 0 + prec:'%+05.3d'\n", nb);

	ft_printf("-----------------------------------------\n");

	/*ft_printf("space% d\n", nb);
	ft_printf("plus:%+d\n", nb);
	ft_printf("precision:%.5d\n", nb);
	ft_printf("space + prec:% .5d\n", nb);
	ft_printf("Plus + prec / grande:%+.5d\n", nb);
	ft_printf("Plus + prec / petite:%+.0d\n", nb);
	ft_printf("Prec + 0:%0.5d\n", nb);
	ft_printf("Prec + minus:%-.5d\n", nb);
	ft_printf("size:'%5d'\n", nb);
	ft_printf("size + space:'% 5d'\n", nb);
	ft_printf("size + plus:'%+5d'\n", nb);
	ft_printf("size + minus:'%-5d'\n", nb);*/
	ft_printf("size + 0:'%05d'\n", nb);
	ft_printf("size + 0 + plus:'%+05d'\n", nb);
	ft_printf("size + 0 + plus:'%0+5d'\n", nb);
	ft_printf("size + 0 + prec:'%05.3d'\n", nb);
	ft_printf("size + minus + prec:'%-5.3d'\n", nb);
	ft_printf("size + plus + 0 + prec:'%+05.3d'\n", nb);

/*	ft_printf("space% i\n", nb);
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
	ft_printf("size + minus + plus + prec:%-+5.3i\n", nb);*/
	printf("\ntest basique:'%s'\n", str);
	printf("precision / zero:'%.0s'\n", str);
	printf("precision / petite:'%.5s'\n", str);
	printf("precision / grande:'%.15s'\n", str);
	printf("prec + minus:'%-.5s'\n", str);
	printf("size / petite:'%5s'\n", str);
	printf("size / grande:'%15s'\n", str);
	printf("Minus + size / petite:'%-5s'\n", str);
	printf("Minus + size / grande:'%-15s'\n", str);
	printf("Minus + size + prec:'%-15.5s'\n", str);
	printf("NULL:'%12s'\n", NULL);
	printf("NULL:'%1s'\n", NULL);
	printf("NULL:'%-5.6s'\n", NULL);
	printf("NULL:'%-.8s'\n", NULL);
	printf("NULL:'%.12s'\n", NULL);
	printf("empty:'%-.5s'\n", "");
	printf("empty:'%-1.32s'\n", "");
	printf("empty:'%1.4s'\n", "");
	printf("empty:'%23s'\n", "");

	ft_printf("test basique:'%s'\n", str);
	ft_printf("precision / zero:'%.0s'\n", str);
	ft_printf("precision / petite:'%.5s'\n", str);
	ft_printf("precision / grande:'%.15s'\n", str);
	ft_printf("prec + minus:'%-.5s'\n", str);
	ft_printf("size / petite:'%5s'\n", str);
	ft_printf("size / grande:'%15s'\n", str);
	ft_printf("Minus + size / petite:'%-5s'\n", str);
	ft_printf("Minus + size / grande:'%-15s'\n", str);
	ft_printf("Minus + size + prec:'%-15.5s'\n", str);
	ft_printf("NULL:'%12s'\n", NULL);
	ft_printf("NULL:'%1s'\n", NULL);
	ft_printf("NULL:'%-5.6s'\n", NULL);
	ft_printf("NULL:'%-.8s'\n", NULL);
	ft_printf("NULL:'%.12s'\n", NULL);
	ft_printf("empty:'%-.5s'\n", "");
	ft_printf("empty:'%-1.32s'\n", "");
	ft_printf("empty:'%1.4s'\n", "");
	ft_printf("empty:'%23s'\n\n", "");

	printf("ret = %d\n", printf("test basique:'%s'", str));
	printf("ret = %d\n", printf("precision / zero:'%.0s'", str));
	printf("ret = %d\n",printf("precision / petite:'%.5s'", str));
	printf("ret = %d\n",printf("precision / grande:'%.15s'", str));
	printf("ret = %d\n",printf("prec + minus:'%-.5s'", str));
	printf("ret = %d\n",printf("size / petite:'%5s'", str));
	printf("ret = %d\n",printf("size / grande:'%15s'", str));
	printf("ret = %d\n",printf("Minus + size / petite:'%-5s'", str));
	printf("ret = %d\n",printf("Minus + size / grande:'%-15s'", str));
	printf("ret = %d\n",printf("Minus + size + prec:'%-15.5s'", str));
	printf("ret = %d\n",printf("NULL:'%12s'", NULL));
	printf("ret = %d\n",printf("NULL:'%1s'", NULL));
	printf("ret = %d\n",printf("NULL:'%-5.6s'", NULL));
	printf("ret = %d\n",printf("NULL:'%-.8s'", NULL));
	printf("ret = %d\n",printf("NULL:'%.12s'", NULL));
	printf("ret = %d\n",printf("empty:'%-.5s'", ""));
	printf("ret = %d\n",printf("empty:'%-1.32s'", ""));
	printf("ret = %d\n",printf("empty:'%1.4s'", ""));
	printf("ret = %d\n",printf("empty:'%23s'", ""));

	printf("---------------------------------------------\n");
	printf("ret = %d\n",ft_printf("test basique:'%s'", str));
	printf("ret = %d\n",ft_printf("precision / zero:'%.0s'", str));
	printf("ret = %d\n",ft_printf("precision / petite:'%.5s'", str));
	printf("ret = %d\n",ft_printf("precision / grande:'%.15s'", str));
	printf("ret = %d\n",ft_printf("prec + minus:'%-.5s'", str));
	printf("ret = %d\n",ft_printf("size / petite:'%5s'", str));
	printf("ret = %d\n",ft_printf("size / grande:'%15s'", str));
	printf("ret = %d\n",ft_printf("Minus + size / petite:'%-5s'", str));
	printf("ret = %d\n",ft_printf("Minus + size / grande:'%-15s'", str));
	printf("ret = %d\n",ft_printf("Minus + size + prec:'%-15.5s'", str));
	printf("ret = %d\n",ft_printf("NULL:'%12s'", NULL));
	printf("ret = %d\n",ft_printf("NULL:'%1s'", NULL));
	printf("ret = %d\n",ft_printf("NULL:'%-5.6s'", NULL));
	printf("ret = %d\n",ft_printf("NULL:'%-.8s'", NULL));
	printf("ret = %d\n",ft_printf("NULL:'%.12s'", NULL));
	printf("ret = %d\n",ft_printf("empty:'%-.5s'", ""));
	printf("ret = %d\n",ft_printf("empty:'%-1.32s'", ""));
	printf("ret = %d\n",ft_printf("empty:'%1.4s'", ""));
	printf("ret = %d\n",ft_printf("empty:'%23s'", ""));


	return (0);
}
