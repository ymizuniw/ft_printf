/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:17:18 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/12 18:46:43 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//you haven't understood this yet.

int apply_format_unsigned(unsigned int n, t_format f, t_buffer *buf)
{
	char	num[11];
	int 	len;
	int		count;

	len = utoa_buf(num, n);
	if (f.precision_on && f.precision == 0, n == 0)
		count += put_nchar_buf('0', f.width - len, buf);
	len = 0;

	count = 0;
	if (!f.flag_minus && f.flag_zero && !f.precision_on)
		count += put_nchar_char_buf('0', f.width - len, buf);
	else if(!f.flag_minus)
		count += put_nchar_buf(' ', f.width - ((f.precision > len) ? f.precision : len), buf);
	//ternaries are forbidden.
	count += putnchar_buf('0', f.precision - len, buf);
	count += buffer_write(buf, num + (10 - len), len);
	if (f.flag_minus)
		count += put_nchar_buf(' ', f.width - count, buf);
	return (count);
}
