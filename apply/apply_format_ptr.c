/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:48:25 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/24 05:07:43 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	apply_format_ptr(void *ptr_value, t_format f, t_buffer *buf)
{
	char	ptr[19];
	int		len;
	int		count;

	if (!ptr_value)
	{
		buffer_write(buf, "(nil)", 5);
		return (5);
	}
	len = utoa_base_buf(ptr, (unsigned long)ptr_value, "0123456789abcdef");
	count = 0;
	if (!f.flag_minus && f.width > len + 2)
		count += put_nchar_buf(' ', f.width - (len + 2), buf);
	buffer_write(buf, "0x", 2);
	count += 2;
	buffer_write(buf, ptr, len);
	count += len;
	if (f.flag_minus && f.width > count)
		count += put_nchar_buf(' ', f.width - count, buf);
	return (count);
}
