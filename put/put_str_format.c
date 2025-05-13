/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_format_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:32:11 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 19:28:18 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str_format(char *s, t_format f, t_buffer *buf)
{
	int	len;
	int	padding;
	int	count;

	if (!s)
		s = "(null)"; // what's this?
	len = ft_strlen(s);
	if (f.precision_on && f.precision < len)
		len = f.precision;
	padding = (f.width > len) ? f.width - len : 0;
	count = 0;
	if (!f.flag_minus)
		count += put_nchar_buf(' ', padding, buf);
	buffer_write(buf, s, len);
	count += len;
	if (f.flag_minus)
		count += put_nchar_buf(' ', padding, buf);
	return (count);
}
