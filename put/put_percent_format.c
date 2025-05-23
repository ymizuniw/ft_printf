/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_percent_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:43:21 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/24 05:08:33 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static char	zero_or_space(int flag_zero, int flag_minus)
{
	if (flag_zero && !flag_minus)
		return ('0');
	return (' ');
}

int	put_percent_format(t_format f, t_buffer *buf)
{
	int		count;
	char	padding;

	count = 0;
	padding = zero_or_space(f.flag_zero, f.flag_minus);
	if (!f.flag_minus)
		count += put_nchar_buf(padding, f.width - 1, buf);
	buffer_write_char(buf, '%');
	count++;
	if (f.flag_minus)
		count += put_nchar_buf(' ', f.width - 1, buf);
	return (count);
}
