/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:44:16 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/12 15:05:05 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	len;

	va_start(args, format);
	buf.len = 0;
	buf.total = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] = '%')
			i += dispatch_format_bonus(format + i + 1, args, &buf);
		else
			buffer_write_char(&buf, format[i++]);
	}
	va_end(args);
	buffer_flush(&buf);
	return(buf.total);
}
