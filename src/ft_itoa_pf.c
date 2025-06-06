/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:35:58 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 11:37:40 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*zero_min_case(int n)
{
	if (n == 0)
		return (ft_strndup("0", 1));
	else
		return (ft_strndup("-2147483648", 11));
}

static char	*alloc_buf(size_t len)
{
	char	*buf_res;

	buf_res = malloc((len + 1) * sizeof(char));
	if (!buf_res)
		return (NULL);
	return (buf_res);
}

static void	set_buf_res(char *buf_res, int num, int sign, size_t len)
{
	if (sign == 1)
		buf_res[0] = '-';
	buf_res[len] = '\0';
	while (num > 0)
	{
		buf_res[--len] = '0' + (num % 10);
		num /= 10;
	}
}

static size_t	count_digit(int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_pf(const int n)
{
	char	*buf_res;
	int		num;
	int		sign;
	size_t	len;

	sign = 0;
	len = 0;
	if ((n == 0) || (n == -2147483648))
		return (zero_min_case(n));
	if (n < 0)
	{
		num = -n;
		sign = 1;
		len++;
	}
	else
		num = n;
	len += count_digit(num);
	buf_res = alloc_buf(len);
	if (!buf_res)
		return (NULL);
	set_buf_res(buf_res, num, sign, len);
	return (buf_res);
}
