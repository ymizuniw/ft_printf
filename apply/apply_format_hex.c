/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:52:36 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 20:34:56 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char  *is_upper_hex(const char *base, int upper)
{
	if (upper == 1)
		base = "0123456789ABCDEF";
	else if (upper == 0)
		base = "0123456789abcdef";
	return (base);
}

int	apply_format_hex(unsigned int n, t_format f, t_buffer *buf, int upper)
{
	char		num[17];
	const char	*base;
	int			len;
	int			count;
	int			has_prefix;

	base = is_upper_hex(base, upper);
	len = utoa_buf(num, (unsigned long)n, base);
	has_prefix = (f.flag_hash && n != 0);
	if (f.precision_on && f.precision == 0 && n == 0)
		len = 0;
	count = 0;
	if (!f.flag_minus && f.flag_zero && !f.precision_on)
		count += print_padding_int(f, len, has_prefix * 2, buf);
	if (has_prefix)
	{
		buffer_write_char(buf, '0');
		buffer_write_char(buf, (upper) ? 'X' : 'x');
		count += 2;
	}
	count += buffer_write(buf, num + (17 - len), len);
	if (f.flag_minus)
		count += put_nchar_buf(' ', f.width - count, buf);
	return (count);
}
