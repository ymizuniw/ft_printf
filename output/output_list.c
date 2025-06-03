/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 05:07:17 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/03 01:56:56 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	output_list(t_list *node, size_t *total_len)
{
	t_token	*token;
	char *out_str;
	size_t	out_len;

	token = (t_token *)node->content;
	out_str = apply_format(token, token->format);
	if (!out_str)
		return (-1);
	out_len = output_token((const char *)out_str, token->lens->total);
	*total_len += out_len;
	return (0);
}
