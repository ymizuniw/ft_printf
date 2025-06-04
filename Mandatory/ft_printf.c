/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 01:14:22 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 04:25:03 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		token_array_size;
	int		out_len;
	char	**tokens;

	out_len = 0;
	va_start(ap, format);
	token_array_size = search_size_token(format);
	tokens = set_output_tokens(ap, format, token_array_size);
	if (!tokens)
		return (-1);
	out_len = buffer_output(tokens);
	va_end(ap);
	free_tokens_all(t_index, token);
	return (out_len);
}
