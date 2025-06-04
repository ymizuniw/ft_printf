/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:39:18 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 00:31:41 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

// int	main(void)
// {
// 	int	n;
// 	int	m;

// 	n = ft_printf("Hello, %s! Number: %d, Hex: %#x\n", "world", 42, 42);
// 	m = printf("Hello, %s! Number: %d, Hex: %#x\n", "world", 42, 42);
// 	// ft_printf("%#x", 42);
// 	printf("%d\n", n);
// 	printf("%d\n", m);
// 	ft_printf("%%%%\n");
// 	printf("%%%%\n");
// 	ft_printf("\n");
// 	printf("\n");
// 	return (0);
// }

int	main(void)
{
	int	ret1, ret2;
	char	c = 'A';
	char	*str = "42Tokyo";
	char	*null_str = NULL;
	int		num = -1234;
	int		pos_num = 5678;
	unsigned int uval = UINT_MAX;

	// srand((unsigned int)time(NULL));

	int i = 100;
	while (i-- > 0)
{
	//--- CHAR ---
	ret1 = ft_printf("c: [%5c] [%-5c]\n", c, c);
	ret2 = printf("c: [%5c] [%-5c]\n", c, c);
	printf("ret: %d == %d\n\n", ret1, ret2);

	//--- STRING ---
	ret1 = ft_printf("s: [%10.3s] [%-10.4s] [%s] [%s]\n", str, str, "", null_str);
	ret2 = printf("s: [%10.3s] [%-10.4s] [%s] [%s]\n", str, str, "", null_str);
	printf("ret: %d == %d\n\n", ret1, ret2);

	//--- DECIMAL / INTEGER ---
	ret1 = ft_printf("d: [%10.5d] [% 10.5d] [%010d] [%-10d]\n", num, pos_num, num, pos_num);
	ret2 = printf("d: [%10.5d] [% 10.5d] [%010d] [%-10d]\n", num, pos_num, num, pos_num);
	printf("ret: %d == %d\n\n", ret1, ret2);

	ret1 = ft_printf("i: [%+5.3i] [%-5.3i]\n", num, pos_num);
	ret2 = printf("i: [%+5.3i] [%-5.3i]\n", num, pos_num);
	printf("ret: %d == %d\n\n", ret1, ret2);

	// --- UNSIGNED ---
	ret1 = ft_printf("u: [%10u] [%-10.8u] [%08u]\n", uval, 42, 0);
	ret2 = printf("u: [%10u] [%-10.8u] [%08u]\n", uval, 42, 0);
	printf("ret: %d == %d\n\n", ret1, ret2);

	// --- HEXADECIMAL (lowercase) ---
	ret1 = ft_printf("x: [%#10x] [%#08x] [%#-10.4x]\n", 42, 0, 0x2a);
	ret2 = printf("x: [%#10x] [%#08x] [%#-10.4x]\n", 42, 0, 0x2a);
	printf("ret: %d == %d\n\n", ret1, ret2);

	// --- HEXADECIMAL (uppercase) ---
	ret1 = ft_printf("X: [%#10X] [%#08X] [%#-10.4X]\n", 42, 0, 0x2a);
	ret2 = printf("X: [%#10X] [%#08X] [%#-10.4X]\n", 42, 0, 0x2a);
	printf("ret: %d == %d\n\n", ret1, ret2);

	// --- PERCENT ---
	// ret1 = ft_printf("percent: [%%] [%%10] [%-5%]\n");
	// ret2 = printf("percent: [%%] [%%10] [%-5%]\n");
	// printf("ret: %d == %d\n\n", ret1, ret2);

}
	return (0);
}
