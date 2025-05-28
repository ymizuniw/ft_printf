/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:17:33 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/24 05:07:57 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	utoa_buf(char *buf, unsigned int value)
{
	char	digits[11];
	int		write_index;
	int		read_index;
	int		digit_count;

	write_index = 10;
	if (value == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return (1);
	}
	while (value > 0)
	{
		digits[write_index--] = '0' + (value % 10);
		value /= 10;
	}
	digit_count = 10 - write_index;
	read_index = 0;
	while (++write_index < 11)
		buf[read_index++] = digits[write_index];
	buf[read_index] = '\0';
	return (digit_count);
}
//! buf, n != unsigned int _, handlings are needed?
