/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:09:07 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/09 17:57:50 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_token(char *token_unit)
{
	return (write(1, token_unit, ft_strlen(token_unit)));
}

void	output_tokens(char **tokens, t_tk_params *tk_params)
{
	tk_params->out_len += print_token(tokens[tk_params->count_out_tokens]);
	if (tk_params->out_len < 0)
		return (get_token_error_free(tokens, tk_params->count_out_tokens),
			ft_putstr_fd("output failed", 1));
	tk_params->count_out_tokens++;
}
