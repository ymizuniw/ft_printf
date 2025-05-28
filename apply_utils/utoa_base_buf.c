/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa_base_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:43:17 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/27 17:16:24 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	*utoa_base_buf(unsigned long value, const char *base)
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
	return (reversed);
}
// //!buf, !base.
