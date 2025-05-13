/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:17:33 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/14 02:19:33 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	utoa_buf(char *buf, unsigned int n)
{
	int	buf_index;

	buf_index = 10;
	if (n == 0)
	{
		buf[--buf_index] = '0';
		return (1);
	}
	while (n > 0)
	{
		buf[buf_index--] = '0' + (n % 10);
		n /= 10;
	}
	return (10 - buf_index);
}
//! buf, n != unsigned int _, handlings are needed?
