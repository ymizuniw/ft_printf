/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:06:43 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/04 19:06:59 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	output_token(const char *str, size_t len)
{
	size_t	written;
	int		n;

	written = 0;
	while (written < len)
	{
		n = write(1, str + written, len - written);
		if (n < 0)
			return (-1);
		written += n;
	}
	return ((int)written);
}
