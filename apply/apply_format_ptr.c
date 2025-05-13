/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format_ptr_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:48:25 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 20:14:56 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_format_ptr(void *ptr, t_format f, t_buffer *buf)
{
	char	num[18];
	int		len;
	int		count;

	len = utoa_base_buf(num, (unsigned long)ptr, "0123456789abcdef");
	count = 0;
	if (!f.flag_minus)
		count += put_nchar_buf(' ', f.width - (len + 2), buf);
	buffer_write(buf, "0x", 2);
	count += 2;
	count += buffer_write(buf, num + (17 - len), len);
	if (f.flag_minus)
		count += put_nchar_buf(' ', f.width - count, buf);
	return (count);
}
