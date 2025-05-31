/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:39:18 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/31 15:39:19 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	main(void)
{
	int	len1;
	int	len2;

	len1 = ft_printf("Hello, %s! Number: %d, Hex: %#x\n", "world", 42, 42);
	len2 = printf("Hello, %s! Number: %d, Hex: %#x\n", "world", 42, 42);
	ft_printf("ft_printf length: %d\n", len1);
	printf("printf    length: %d\n", len2);
	return (0);
}
