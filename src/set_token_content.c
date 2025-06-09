/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:02:59 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/09 17:53:46 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_token_content(const char *fmt, int fmt_index, int txt_or_arg_len,
		va_list ap)
{
	char	*arg;
	char	spec;

	if (fmt[fmt_index] && fmt[fmt_index] != '%')
		return (ft_strndup(fmt, (size_t)txt_or_arg_len));
	else if (fmt[fmt_index] == '%' && ft_is_spec(fmt[fmt_index + 1]))
	{
		spec = fmt[fmt_index + 1];
		arg = arg_to_ascii(spec, ap);
		if (!arg)
		{
			return (ft_strndup("(null)", 6));
		}
		return (arg);
	}
	else
		return (NULL);
}

int	set_token_content(const char *fmt, char **tokens,
		t_tk_params *tk_params, va_list ap)
{
	char	*tmp_token_content;

	tmp_token_content = get_token_content(fmt, tk_params->fmt_index,
			tk_params->txt_or_arg_len, ap);
	if (!tmp_token_content)
	{
		get_token_error_free(tokens, tk_params->tk_index);
		return (ft_putstr_fd("getting token content failed.", 1), -1);
	}
	tokens[tk_params->tk_index] = tmp_token_content;
	return (1);
}
