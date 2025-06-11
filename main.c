/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 04:49:41 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/11 10:09:26 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int main (void)
{
	int ori,my;

	ori = printf(" %-1c %2c %-3c ", '0', 0, '1');
	printf("\n");
	my = ft_printf(" %-1c %2c %-3c ", '0', 0, '1');
	ft_printf("\n");

	ft_printf("%d, %d\n", ori, my);

	// // TEST 20: %2p with -1
	// printf(" %2p ", (void *)-1);
	// printf("\n");
	// ft_printf(" %2p ", (void *)-1);
	// ft_printf("\n");


	// // TEST 22: %-2p with 1
	// printf(" %-2p ", (void *)1);
	// printf("\n");
	// ft_printf(" %-2p ", (void *)1);
	// ft_printf("\n");

	// // TEST 23: %-2p with 15
	// printf(" %-2p ", (void *)15);
	// printf("\n");
	// ft_printf(" %-2p ", (void *)15);
	// ft_printf("\n");

	// // TEST 24: %-3p with 16
	// printf(" %-3p ", (void *)16);
	// printf("\n");
	// ft_printf(" %-3p ", (void *)16);
	// ft_printf("\n");

	// // TEST 25: %-4p with 17
	// printf(" %-4p ", (void *)17);
	// printf("\n");
	// ft_printf(" %-4p ", (void *)17);
	// ft_printf("\n");

	// // TEST 26: %-9p %-10p with LONG_MIN, LONG_MAX
	// printf(" %-9p %-10p ", (void *)LONG_MIN, (void *)LONG_MAX);
	// printf("\n");
	// ft_printf(" %-9p %-10p ", (void *)LONG_MIN, (void *)LONG_MAX);
	// ft_printf("\n");

	// // TEST 27: %-11p %-12p with INT_MIN, INT_MAX
	// printf(" %-11p %-12p ", (void *)INT_MIN, (void *)INT_MAX);
	// printf("\n");
	// ft_printf(" %-11p %-12p ", (void *)INT_MIN, (void *)INT_MAX);
	// ft_printf("\n");

	// // TEST 28: %-13p %-14p with ULONG_MAX, -ULONG_MAX
	// printf(" %-13p %-14p ", (void *)ULONG_MAX, (void *)(-ULONG_MAX));
	// printf("\n");
	// ft_printf(" %-13p %-14p ", (void *)ULONG_MAX, (void *)(-ULONG_MAX));
	// ft_printf("\n");

	// // // TEST 29: %-1p %-2p with 0, 0
	// // printf(" %-1p %-2p ", (void *)0, (void *)0);
	// // printf("\n");
	// // ft_printf(" %-1p %-2p ", (void *)0, (void *)0);
	// // ft_printf("\n");

	// // TEST 1: %#x with 0
	// printf(" %#x ", 0);
	// printf("\n");
	// ft_printf(" %#x ", 0);
	// ft_printf("\n");

	// // TEST 25: %#x with LONG_MIN
	// printf(" %#x ", (unsigned long)LONG_MIN);
	// printf("\n");
	// ft_printf(" %#x ", (unsigned long)LONG_MIN);
	// ft_printf("\n");

	// // TEST 29: multiple %#x with various values
	// printf(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf("\n");
	// ft_printf(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// ft_printf("\n");

	return (0);
}

// cc -fsanitize=address -Iinclude -Ilibft main.c libftprintf.a -o a.out
