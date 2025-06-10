/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_and_alloc_tokens.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:57:04 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/11 03:31:06 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initialize_tk_params(t_tk_params *tk_params)
{
	tk_params->tk_index = 0;
	tk_params->txt_or_arg_len = 0;
	tk_params->fmt_index = 0;
	tk_params->token_array_size = 0;
	tk_params->token_start_index = 0;
	tk_params->out_len = 0;
	tk_params->count_out_tokens = 0;
}

static int	get_token_array_size(const char *fmt)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (fmt[i])
	{
		if (fmt[i] && fmt[i] != '%')
		{
			while (fmt[i] && fmt[i] != '%')
				i++;
			size++;
		}
		else if (fmt[i] == '%' && ft_is_spec(fmt[i + 1]))
		{
			i += 2;
			size++;
		}
		else
			return (-1);
	}
	return (size);
}

static int	alloc_tokens(const char *fmt, t_token **tokens,
		t_tk_params *tk_params)
{
	if (!fmt)
		return (ft_putstr_fd("(null)", 1), -1);
	tk_params->token_array_size = get_token_array_size(fmt);
	if (tk_params->token_array_size < 0)
		return (-1);
	*tokens = (t_token *)malloc(sizeof(t_token) * tk_params->token_array_size);
	if (!*tokens)
	{
		ft_putstr_fd("malloc for tokens failed", 1);
		return (-1);
	}
	return (1);
}

int	initialize_and_alloc_tokens(const char *fmt, t_token **tokens,
		t_tk_params *tk_params)
{
	initialize_tk_params(tk_params);
	if (alloc_tokens(fmt, tokens, tk_params) < 0)
		return (-1);
	return (1);
}
