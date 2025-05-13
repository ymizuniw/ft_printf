/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:04:24 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 13:30:16 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char_format(char c, t_format f, t_buffer *buf)
{
	int	count;

	count = 0;
	if (!f.flag_minus)
		count += put_nchar_buf(' ', f.width - 1, buf);
	buffer_write_char(buf, c);
	count++;
	if (f.flag_minus)
		count += put_nchar_buf(' ', f.width - 1, buf);
	return (count);
}
