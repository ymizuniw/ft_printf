/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:32:11 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 21:54:50 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	padding_len(int width, int len)
{
	if (f.width > len)
		return (f.width - len);
	return (0);
}

int	put_str_format(char *s, t_format f, t_buffer *buf)
{
	int	len;
	int	padding;
	int	count;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (f.precision_on && f.precision < len)
		len = f.precision;
	padding = padding_len(f.width, len);
	count = 0;
	if (!f.flag_minus)
		count += put_nchar_buf(' ', padding, buf);
	buffer_write(buf, s, len);
	count += len;
	if (f.flag_minus)
		count += put_nchar_buf(' ', padding, buf);
	return (count);
}
