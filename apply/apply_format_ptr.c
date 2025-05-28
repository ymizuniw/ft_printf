/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:48:25 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/27 17:11:45 by ymizuniw         ###   ########.fr       */
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

	count += 2;
	count += len;
	if (f.flag_minus && f.width > count)
		count += put_nchar_buf(' ', f.width - count, buf);
	return (count);
}
