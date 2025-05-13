/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:09:23 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 13:15:59 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//you haven't understood this yet.

int	apply_format_int(int n, t_format f, t_buffer *buf)
{
	char	num[12];
	int		len;
	int		count;
	int		prefix;

	prefix = (n < 0 || f.flag_plus || f.flag_space);
	len = itoa_buf(num, n);
	if (f.precision_on && f.precision == 0 && n == 0)
		len = 0;

	count = 0;
	count += print_padding_int(f, len, prefix, buf);
	count += print_prefix(n, f, buf);
	count += put_nchar_buf('0', f.precision - len, buf);
	count += buffer_write(buf, num + (11 - len), len);
	if (f.flag_minus)
		count += put_nchar_buf(' ', f.width - count, buf);
	return (count);
}
