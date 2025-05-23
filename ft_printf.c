/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:44:16 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/24 05:30:41 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...)
{
	t_token		*tokens;
	size_t		count;
	va_list		args;
	t_buffer	buf;
	size_t		i;
	int			len;

	va_start(args, format);
	buffer_init(&buf);

	tokens = malloc(sizeof(t_token) * 128);
	if (!tokens)
		return (va_end(args), -1);

	count = tokenize_format(format, tokens, 128, args);
	len = 0;
	i = 0;
	while (i < count)
	{
		if (tokens[i].type == TOK_TEXT)
			len += buffer_write_str(&buf, tokens[i].str);
		else if (tokens[i].type == TOK_CONV)
			len += dispatch_format_token(&tokens[i], args, &buf);
		i++;
	}
	buffer_output(&buf);
	va_end(args);
	return (len);
}
