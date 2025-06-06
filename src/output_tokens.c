/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 01:14:24 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 17:50:34 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_tokens(char **tokens, size_t token_array_size)
{
	size_t		i;
	size_t		out_len;

	i = 0;
	out_len = 0;
	if (!tokens)
		return (-1);
	while (i < token_array_size && tokens[i])
	{
		out_len += write(1, tokens[i], ft_strlen(tokens[i]));
		i++;
	}
	return (out_len);
}
