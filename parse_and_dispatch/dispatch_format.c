/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:44:14 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 16:42:16 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	dispatch_format(const char *s, va_list args, t_buffer *buf)
{
	t_format	f;
	int			i;

	i = 0;
	f = parse_format(s, &i, args);
	if (f.specifier == 'c')
	{
		put_char_format(va_arg(args, int), f, buf);
		return (i + 1);
	}
	if (f.specifier == 's')
	{
		put_str_format(va_arg(args, char *), f, buf);
		return (i + 1);
	}
	if (f.specifier == 'd' || f.specifier == 'i')
	{
		apply_format_int(va_arg(args, int), f, buf);
		return (i + 1);
	}
	if (f.specifier == 'u')
	{
		apply_format_unsigned(va_arg(args, unsigned int), f, buf);
		return (i + 1);
	}
	if (f.specifier == 'x' || f.specifier == 'X')
	{
		apply_format_hex(va_arg(args, unsigned int), f, buf,
				f.specifier == 'X');
		return (i + 1);
	}
	if (f.specifier == 'p')
	{
		apply_format_ptr(va_arg(args, void *), f, buf);
		return (i + 1);
	}
	if (f.specifier == '%')
	{
		put_percent_format(f, buf);
		return (i + 1);
	}
	return (0);
}
