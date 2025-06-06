/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:04:06 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 14:23:35 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	len_digit(unsigned long hex)
{
	size_t	len;

	len = 0;
	while (hex > 0)
	{
		hex /= 16;
		len++;
	}
	return (len);
}

char	*ft_xtoa(unsigned long hex, t_bool is_upper)
{
	unsigned long	num;
	const char		*base;
	char			*new_digit;
	size_t			i;
	size_t			len;

	num = hex;
	i = 0;
	len = 0;
	if (hex == 0)
		return (ft_strndup("0", 1));
	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = len_digit(hex);
	new_digit = malloc(len + 1);
	new_digit[len] = '\0';
	while (num > 0)
	{
		new_digit[--len] = base[num % 16];
		num /= 16;
	}
	return (new_digit);
}
