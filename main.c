/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 03:37:31 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/14 03:39:32 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // printf との比較用

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

	return (0);
}
