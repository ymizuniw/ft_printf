/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:24:20 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/12 21:42:54 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	buffer_write_char(t_buffer *buf, char c)
{
	if (buf->len == PRINTF_BUF_SIZE)
		buffer_flush(buf);
	buf->data[buf->len++] = c;
	buf->total++;
}
