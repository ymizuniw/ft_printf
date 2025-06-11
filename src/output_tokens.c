/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:09:07 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/11 12:34:28 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_token(t_token token)
{
	int	len;

	len = ft_strlen((const char *)token.content);
	if (token.spec == 'c' && token.content[0] == '\0')
		return (write(1, token.content, 1));
	else
		return (write(1, token.content, len));
}

void	output_tokens(t_token *tokens, t_tk_params *tk_params)
{
	tk_params->out_len += print_token(tokens[tk_params->count_out_tokens]);
	if (tk_params->out_len < 0)
	{
		get_token_error_free(tokens, tk_params->count_out_tokens),
		ft_putstr_fd("output failed", 1);
		return ;
	}
	tk_params->count_out_tokens++;
}
