/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nchar_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:29:45 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/14 03:46:19 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	put_nchar_buf(char c, int n, t_buffer *buf)
{
	int	count;

	if (n <= 0)
		return (0);
	count = 0;
	while (count < n)
	{
		buffer_write_char(buf, c);
		count++;
	}
	return (n);
}
