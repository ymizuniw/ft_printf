/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:15:21 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 20:06:22 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buffer_write(t_buffer *buf, const char *s, int len)
{
	int			s_index;
	const int	buf_size;

	buf_size = 1024;
	i = 0;
	while (i < len)
	{
		if (buf->len == )
			buffer_output(buf);
		buf->data[buf->len++] = s[i++];
	}
	buf->total += len;
}
