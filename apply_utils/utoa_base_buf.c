/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa_base_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:43:17 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/24 05:07:55 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	utoa_base_buf(char *buf, unsigned long value, const char *base)
{
	char	reversed[18];
	int		base_len;
	int		i;
	int		j;

	base_len = ft_strlen(base);
	i = 0;
	if (value == 0)
		reversed[i++] = base[0];
	while (value > 0)
	{
		reversed[i++] = base[value % base_len];
		value /= base_len;
	}
	j = 0;
	while (i--)
		buf[j++] = reversed[i];
	buf[j] = '\0';
	return (j);
}
// //!buf, !base.
