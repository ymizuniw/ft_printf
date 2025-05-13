/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:15:21 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 20:57:33 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buffer_write(t_buffer *buf, const char *s, int len)
{
	int			s_index;

	i = 0;
	while (i < len)
	{
		if (buf->len == )
			buffer_output(buf);
		buf->data[buf->len++] = s[i++];
	}
	buf->total += len;
}

void	buffer_write_char(t_buffer *buf, char c)
{
	if (buf->len == PRINTF_BUF_SIZE)
		buffer_output(buf);
	buf->data[buf->len++] = c;
	buf->total++;
}
