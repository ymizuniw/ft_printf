/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:50:25 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/24 05:07:51 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"


int	itoa_buf(char *buf, int value)
{
	char	reversed[12];
	unsigned int	abs_value;
	int		i;
	int		j;

	if (value == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return (1);
	}
	abs_value = (value < 0) ? -((unsigned int)value) : (unsigned int)value;
	i = 0;
	while (abs_value > 0)
	{
		reversed[i++] = '0' + (abs_value % 10);
		abs_value /= 10;
	}
	j = 0;
	while (i--)
		buf[j++] = reversed[i];
	buf[j] = '\0';
	return (j);
}
