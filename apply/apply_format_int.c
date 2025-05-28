/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:09:23 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/27 21:55:44 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

//
//apply_format_int(long long n, t_format f)
//the internal buffer size is 14 (int min(11), sign(1) or prefix(2) + '\0').
//itoa_buf() converts an integer to a string,
//refer to f->precision and malloc(max(width, (sign or presicion or 0) + max(precision, len of itoa_buf))).
//set digits prefix or sign if flag is set, and if - flag isn't, set needed counts(precision - len of itoa_buf) of 0,
//and set digits, and if - flag is, set needed counts(precision - len of itoa_buf) of 0 to the buffer.
//return the length of the string.
//it should detect overflow, and handle as printf() does.

static t_intfmt	get_parts(int n, t_format f)
{
	t_intfmt	ifmt;

	ifmt.len_digits = itoa_buf(NULL, n);
	if (f.precision_on && f.precision == 0 && n == 0)
		ifmt.len_digits = 0;
	ifmt.has_prefix = (n < 0 || f.flag_plus || f.flag_space);
	ifmt.prec_zeros = (f.precision_on && f.precision > ifmt.len_digits)
		? f.precision - ifmt.len_digits : 0;
	ifmt.content_len = ifmt.len_digits + ifmt.prec_zeros + (ifmt.has_prefix ? 1 : 0);
	ifmt.width_padding = (f.width > ifmt.content_len) ? f.width - ifmt.content_len : 0;
	ifmt.total_len = ifmt.content_len + ifmt.width_padding;
	return (ifmt);
}

int	write_intfmt(char *dst, int n, t_format f, char *digits, t_intfmt ifmt)
{
	int i = 0;

	if (!f.flag_minus)
		i += put_nchar_buf_to(dst + i, ' ', ifmt.width_padding);
	i += print_prefix_to(dst + i, n, f);
	i += put_nchar_buf_to(dst + i, '0', ifmt.prec_zeros);
	for (int j = 0; j < ifmt.len_digits; j++)
		dst[i++] = digits[j];
	if (f.flag_minus)
		i += put_nchar_buf_to(dst + i, ' ', ifmt.width_padding);
	dst[i] = '\0';
	return (i);
}

int	apply_format_int(int n, t_format f, char **out)
{
	char			digits[12];
	t_intfmt	ifmt;

	ifmt = get_parts(n, f);
	if (ifmt.len_digits > 0)
		itoa_buf(digits, n);
	*out = malloc(ifmt.total_len + 1);
	if (!*out)
		return (-1);
	return (write_intfmt(*out, n, f, digits, ifmt));
}
