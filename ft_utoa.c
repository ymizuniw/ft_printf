/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:38:01 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 14:01:23 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int u)
{
	unsigned int	num;
	int				len;
	char			*res;

	num = u;
	len = 0;
	if (num == 0)
		return (ft_strndup("0", 1));
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len-- > 0)
	{
		res[len] = '0' + (u % 10);
		u /= 10;
	}
	return (res);
}
