/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:31:37 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/29 03:57:32 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_printf(const char *format, ...)
{
	//parse_format

	//va_start
	//parse_args
	while (*format)
	{
		if (*format == '%')
		{
			if (*format = 'c')
				ft_putchar();
			else if (*format = 's')
				ft_putstr();
			else if (*format = 'd' || *format = 'i')
				ft_putint();
			else if (*format = 'u')
				ft_put_uint();
			else if (*format = 'x' || *format = 'X')
				ft_put_hex();
			else if (*format = 'p')
				ft_put_ptr();
			else if (*format = '%')
				ft_putchar('%');
		}
		format++;
	}
	//return (count)
}

//format structure

//csdiuxXp%

//print_utils

size_t put_char()
size_t put_str()
size_t put_int()
size_t put_uint()
size_t put_hex()
size_t put_hex_upper()
size_t put_ptr()
