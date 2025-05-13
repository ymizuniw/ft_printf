/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write_char_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:24:20 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 18:52:35 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buffer_write_char(t_buffer *buf, char c)
{
	if (buf->len == PRINTF_BUF_SIZE)
		buffer_output(buf);
	buf->data[buf->len++] = c;
	buf->total++;
}
