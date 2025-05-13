/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:23:08 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/14 02:20:44 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdlib.h>

int	init_buffer(t_buffer *buf, int capacity)
{
	buf->data = malloc(capacity);
	buf->len = 0;
	buf->total = 0;
	buf->capacity = 0;
	if (!buf->data)
		return (0);
	buf->capacity = capacity;
	return (1);
}

void	free_buffer(t_buffer *buf)
{
	if (buf->data)
	{
		free(buf->data);
		buf->data = NULL;
	}
	buf->len = 0;
	buf->capacity = 0;
}
