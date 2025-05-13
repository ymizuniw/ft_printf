/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 03:37:31 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/14 04:14:10 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_printf("Hello, %s! Number: %d\n", "world", 42);
	ret2 = printf("Hello, %s! Number: %d\n", "world", 42);

	ft_printf("ft_printf return: %d\n", ret1);
	printf("libc     return: %d\n", ret2);

	ft_printf("Test: %s %d %x %c %u %p %s %d %x %c %u %p\n",
		"hello", 42, 255, 'A', 3000000000U, (void *)0xdeadbeef,
		"world", -1, 0xabcdef, 'Z', 123456789U, (void *)0x12345678);

	printf("Test: %s %d %x %c %u %p %s %d %x %c %u %p\n",
		"hello", 42, 255, 'A', 3000000000U, (void *)0xdeadbeef,
		"world", -1, 0xabcdef, 'Z', 123456789U, (void *)0x12345678);

	return (0);
}
