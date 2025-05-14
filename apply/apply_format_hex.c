/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:52:36 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/14 13:15:43 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	char	get_hex_prefix(int upper)
{
	if (upper)
		return ('X');
	return ('x');
}

static const	char	*get_hex_base(int upper)
{
	const char	*base_to;

	if (upper == 1)
	{
		base_to = "0123456789ABCDEF";
		return (base_to);
	}
	else if (upper == 0)
	{
		base_to = "0123456789abcdef";
		return (base_to);
	}
	return (NULL);
}

static	int	buffer_write_prefix(t_buffer *buf, int has_prefix,
				int upper)
{
	int	add_element;

	add_element = 0;
	if (has_prefix)
	{
		buffer_write_char(buf, '0');
		buffer_write_char(buf, get_hex_prefix(upper));
		add_element = 2;
	}
	return (add_element);
}

int	apply_format_hex(unsigned int n, t_format f, t_buffer *buf, int upper)
{
	char		num[17];
	const char	*base;
	int			len;
	int			count;
	int			has_prefix;

	base = get_hex_base(upper);
	len = utoa_base_buf(num, (unsigned long)n, base);
	has_prefix = (f.flag_hash && n != 0);
	if (f.precision_on && f.precision == 0 && n == 0)
		len = 0;
	count = 0;
	if (!f.flag_minus && f.flag_zero && !f.precision_on)
		count += print_padding_int(f, len, has_prefix * 2, buf);
	count += buffer_write_prefix(buf, has_prefix, upper);
	buffer_write(buf, num, len);
	count += len;
	if (f.flag_minus && f.width > count)
		count += put_nchar_buf(' ', f.width - count, buf);
	return (count);
}
