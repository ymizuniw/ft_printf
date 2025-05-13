/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_buf_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:50:25 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 19:27:30 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_itoa_buf(char *buf, int n)
{
	unsigned int	num;
	int				buf_index;

	i = 11;
	buf[buf_index--] = '\0';
	if (n == 0)
	{
		buf[buf_index--] = '0';
		return (1);
	}
	num = (n < 0) ? -((unsigned int)n) : (unsigned int)n;
	while (num > 0)
	{
		buf[buf_index--] = '0' + (num % 10);
		num /= 10;
	}
	return (11 - buf_index - 1);
}
