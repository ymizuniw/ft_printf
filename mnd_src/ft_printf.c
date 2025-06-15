/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 04:55:29 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/12 23:16:16 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	t_tk_params	tk_params;
	t_token		*tokens;
	va_list		ap;
	va_list		aq;

	va_start(ap, fmt);
	va_copy(aq, ap);
	tokens = NULL;
	if (initialize_and_alloc_tokens(fmt, &tokens, &tk_params) < 0)
		return (-1);
	while (tk_params.tk_index < tk_params.token_array_size)
	{
		if (set_content_len(fmt, &tk_params, aq) < 0 || set_token_content(fmt,
				tokens, &tk_params, ap) < 0)
			return (-1);
		adjust_index(fmt, &tk_params);
	}
	while (tk_params.token_array_size > tk_params.count_out_tokens)
		output_tokens(tokens, &tk_params);
	destruct_tokens(tokens, tk_params.token_array_size);
	va_end(aq);
	va_end(ap);
	return (tk_params.out_len);
}
