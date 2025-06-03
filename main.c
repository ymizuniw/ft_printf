/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:39:18 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/04 05:09:23 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

int	main(void)
{
	int n = ft_printf("Hello, %s! Number: %d, Hex: %#x\n", "world", 42, 42);
	int m = printf("Hello, %s! Number: %d, Hex: %#x\n", "world", 42, 42);
	printf("%d", n);
	printf("%d", m);
	return (0);
}
