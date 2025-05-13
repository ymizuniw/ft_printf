/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:15:21 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 13:29:07 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buffer_write(t_buffer *buf, const char *s, int len)
{
	int	s_index;

	i = 0;
	while (i < len)
	{
		if (buf->len == PRINTF_BUF_SIZE)
			buffer_flush(buf);
		buf->data[buf->len++] = s[i++];
	}
	buf->total += len;
}
