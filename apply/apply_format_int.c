/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:09:23 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/24 05:07:32 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	apply_format_int(int n, t_format f, t_buffer *buf)
{
	char	num[12];
	int		len;
	int		count;
	int		has_prefix;

	len = itoa_buf(num, n);
	if (f.precision_on && f.precision == 0 && n == 0)
		len = 0;
	has_prefix = (n < 0 || f.flag_plus || f.flag_space);
	count = 0;
	count += print_padding_int(f, len, has_prefix ? 1 : 0, buf);
	count += print_prefix(n, f, buf);
	if (f.precision_on && f.precision > len)
		count += put_nchar_buf('0', f.precision - len, buf);
	buffer_write(buf, num, len);
	count += len;
	if (f.flag_minus && f.width > count)
		count += put_nchar_buf(' ', f.width - count, buf);
	return (count);
}
