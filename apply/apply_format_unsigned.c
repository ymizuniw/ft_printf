/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:17:18 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/14 02:01:18 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	get_precision_or_len(int precision, int len)
{
	if (precision > len)
		return (precision);
	return (len);
}

int	apply_format_unsigned(unsigned int n, t_format f, t_buffer *buf)
{
	char	num[11];
	int		len;
	int		count;

	len = utoa_buf(num, n);
	count = 0;
	if (f.precision_on && f.precision == 0 && n == 0)
	{
		if (f.width > 0)
			count += put_nchar_buf(' ', f.width, buf);
		return (count);
	}
	if (!f.flag_minus && f.flag_zero && !f.precision_on)
		count += put_nchar_buf('0', f.width - len, buf);
	else if (!f.flag_minus)
		count += put_nchar_buf(' ', f.width - get_precision_or_len(f.precision, len), buf);
	if (f.precision_on && f.precision > len)
		count += put_nchar_buf('0', f.precision - len, buf);
	buffer_write(buf, num + (10 - len), len);
	count += len;
	if (f.flag_minus && f.width > count)
		count += put_nchar_buf(' ', f.width - count, buf);
	return (count);
}
