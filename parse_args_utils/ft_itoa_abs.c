/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_abs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:50:25 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/04 07:32:14 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*ft_itoa_abs(int n)
{
	char			buf[12];
	unsigned int	num;
	int				buf_index;
	int				rev_index;
	char			*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		num = -n;
	else
		num = n;
	buf_index = 0;
	while (num > 0)
	{
		buf[buf_index++] = '0' + (num % 10);
		num /= 10;
	}
	str = malloc(buf_index + 1);
	if (!str)
		return (NULL);
	str[buf_index] = '\0';
	rev_index = 0;
	while (buf_index-- > 0)
		str[rev_index++] = buf[buf_index];
	return (str);
}
