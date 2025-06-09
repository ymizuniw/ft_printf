/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:29:19 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/09 10:05:53 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_xtoa(unsigned long n, t_bool is_upper)
{
	char		buf[17];
	const char	*base;
	int			i;
	char		*str;
	int			j;

	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	while (n > 0)
	{
		buf[i++] = base[n % 16];
		n /= 16;
	}
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	j = 0;
	while (i-- > 0)
		str[j++] = buf[i];
	return (str);
}
