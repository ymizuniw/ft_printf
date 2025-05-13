/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding_int_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:31:38 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 19:28:09 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_padding_int(t_format f, int len, int has_prefix, t_buffer *buf)
{
	int		total_len;
	int		padding_len;
	char	padding_char;
	int		count;

	padding_char = ' ';
	if (f.flag_zero && !f.flag_minus && !f.precision_on)
		padding_char = '0';
	total_len = len + has_prefix;
	if (f.precision_on && f.precision > len)
		total_len = f.precision + has_prefix;
	pad_len = f.width - total_len;
	if (pad_len < 0)
		pad_len = 0;
	count = 0;
	while (count < pad_len)
		count += put_nchar_buf(pad_char, pad_len, buf);
	return (count);
}
