/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 03:28:34 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/24 05:08:20 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static void	get_conv_token(const char *fmt, t_token *tokens, va_list ap,
		size_t *place)
{
	int		j;
	va_list	ap_copy;

	va_copy(ap_copy, ap);
	j = 0;
	tokens->type = TK_CONV;
	tokens->format = parse_format(fmt, &j, ap_copy);
	tokens->str = ft_substr(fmt, 0, j + 1);
	va_end(ap_copy);
	*place += j + 1;
}

static void	get_txt_token(const char *fmt, t_token *tokens, size_t *place)
{
	size_t	len;

	len = 0;
	while (fmt[len] && fmt[len] != '%')
		len++;
	tokens->type = TK_TEXT;
	tokens->str = ft_substr(fmt, 0, len);
	*place += len;
}

size_t	tokenize_format(const char *fmt, t_token *tokens, size_t max, va_list ap)
{
	size_t	index;
	size_t	place;

	index = 0;
	place = 0;
	while (*fmt && index < max)
	{
		if (*fmt == '%')
			get_conv_token(fmt, &tokens[index], ap, &place);
		else
			get_txt_token(fmt, &tokens[index], &place);
		fmt += place;
		index++;
	}
	return (index);
}
