/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_abs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:50:25 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/30 22:28:55 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*ft_itoa_abs(int n)
{
	char			buf[12];
	unsigned int	num;
	int				i;
	char			*str;

	if (n == 0)
		return (ft_strdup("0"));
	num = (n < 0) ? -n : n;
	i = 0;
	while (num > 0)
	{
		buf[i++] = '0' + (num % 10);
		num /= 10;
	}
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i-- > 0)
		str[i] = buf[i];
	return (str);
}
