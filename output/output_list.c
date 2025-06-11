/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 05:07:17 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/11 10:28:37 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	output_list(t_list *node)
{
	t_token	*token;
	char	*out_str;
	int		out_len;
	int		total_len;

	total_len = 0;
	while (node)
	{
		token = (t_token *)node->content;
		if (token->type == TXT)
			out_len = write(1, token->block, ft_strlen(token->block));
		else if (token->type == CONV && token->format)
		{
			out_str = apply_format(token, token->format);
			if (!out_str)
				return (-1);
			out_len = output_token((const char *)out_str, token->lens->total,
					token->format->spec);
			free(out_str);
		}
		else
			return (-1);
		if (out_len < 0)
			return (-1);
		total_len += out_len;
		node = node->next;
	}
	return (total_len);
}
