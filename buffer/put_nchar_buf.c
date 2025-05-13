/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nchar_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:29:45 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 20:57:45 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_nchar_buf(char c, int n, t_buffer *buf)
{
	int	count;

	count = 0;
	while (i < n)
	{
		buffer_write_char(buf, c);
		count++;
	}
	return (n);
}
