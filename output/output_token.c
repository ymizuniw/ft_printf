/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:06:43 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/11 11:36:31 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// int	output_token(const char *token, size_t len)
// {
// 	ssize_t	written;
// 	int		n;


// 	written = 0;
// 	while ((size_t)written < len)
// 	{
// 		n = write(1, token + written, len - written);
// 		if (n < 0)
// 			return (-1);
// 		written += n;
// 	}
// 	return (written);
// }

int	output_token(const char *token, size_t len, int spec)
{
	ssize_t	written;
	int		n;

	written = 0;
	if (spec == 'c' && token[0] == '\0' && len == 1)
		return (write(1, "\0", 1));
	while ((size_t)written < len)
	{
		n = write(1, token + written, len - written);
		if (n < 0)
			return (-1);
		written += n;
	}
	return (written);
}
