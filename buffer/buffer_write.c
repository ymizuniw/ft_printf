/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:15:21 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/14 03:43:42 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	buffer_write(t_buffer *buf, const char *s, int len)
{
	int			s_index;

	s_index = 0;
	while (s_index < len)
	{
		if (buf->len == buf->capacity)
			buffer_output(buf);
		buf->data[buf->len++] = s[s_index++];
	}
}

void	buffer_write_char(t_buffer *buf, char c)
{
	if (buf->len == buf->capacity)
		buffer_output(buf);
	buf->data[buf->len++] = c;
}
