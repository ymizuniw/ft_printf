/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_percent_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:43:21 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/12 22:56:21 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_percent_format(t_format f, t_buffer *buf)
{
	int		count;
	char 	padding;

	count = 0;
	paddig = (f.flag_zero && !f.flag_minus) ? '0' : ' ';
	if (!f.flag_minus)
		count += put_nchar_buf(padding, f.width - 1, buf);
	buffer_write_char(buf, "%");
	count++;
	if (f.flag_minus)
		count += put_nchar_buf(' ', f.width - 1, buf);
	return (count);
}
