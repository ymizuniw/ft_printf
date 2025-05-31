/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:29:19 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/31 15:37:15 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*xtoa(unsigned long num, t_bool is_upepr)
{
	char		buf[9];
	const char	*base;
	int			buf_index;
	char		*str;

	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	buf_index = 0;
	while (n > 0)
	{
		buf[buf_index++] = base[n % 16];
		n /= 16;
	}
	str = malloc(buf_index + 1);
	if (!str)
		return (NULL);
	str[buf_index] = '\0';
	while (buf_index-- > 0)
		str[buf_index] = buf[buf_index];
	return (str);
}
