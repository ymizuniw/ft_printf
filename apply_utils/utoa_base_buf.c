/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa_base_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:43:17 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 21:14:41 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	utoa_base_buf(char *buf, unsigned long n, const char *base)
{
	int	base_len;
	int	buf_index;

	base_len = ft_strlen(base);
	buf_index = 17;
	buf[buf_index--] = '\0';
	if (n == 0)
	{
		buf[buf_index--] = base[0] return (1);
	}
	while (n > 0)
	{
		buf[buf_index--] = base[n % base_len];
		n /= base_len;
	}
	return (17 - buf_index - 1);
}
//! buf, !base.
