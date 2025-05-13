/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:44:16 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 23:24:20 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define PRINTF_CAPACITY 1024

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_buffer	buf;
	int			i;

	init_buffer(&buf, PRINTF_CAPACITY);
	va_start(args, format);
	buf.len = 0;
	buf.total = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i += dispatch_format(format + i + 1, args, &buf);
		else
			buffer_write_char(&buf, format[i++]);
	}
	va_end(args);
	buffer_output(&buf);
	return (buf.total);
}
