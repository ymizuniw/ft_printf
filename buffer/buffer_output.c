/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:27:14 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/14 03:17:07 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	buffer_output(t_buffer *buf)
{
	write(1, buf->data, buf->len);
	buf->total += buf->len;
	buf->len = 0;
}
