/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:50:25 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/28 17:41:41 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

#include <limits.h>

//convert an integer to a string and store it in buf.
//return the length of the string.
//over/underflowは考慮しない。INT_MIN is handled in
//the casging of int to unsigned int.
int	ft_itoa_buf(char *buf, int n)
{
	char	tmp[12];
	unsigned int	num;
	int		i = 0;
	int		j = 0;
	int		is_negative = (n < 0);

	if (n == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return 1;
	}
	num = (n < 0) ? (unsigned int)(-((long)n)) : (unsigned int)n;
	while (num > 0)
	{
		tmp[i++] = '0' + (num % 10);
		num /= 10;
	}
	if (is_negative)
		buf[j++] = '-';
	while (i-- > 0)
		buf[j++] = tmp[i];

	buf[j] = '\0';
	return j;
}
