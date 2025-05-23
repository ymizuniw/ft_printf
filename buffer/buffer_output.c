/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:27:14 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/24 05:08:03 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	buffer_output(t_buffer *buf)
{
	write(1, buf->data, buf->len);
	buf->total += buf->len;
	buf->len = 0;
}
