/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:08:12 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/09 17:45:57 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	adjust_index(const char *fmt, int token_start_index,
		t_tk_params *tk_params)
{
	if (fmt[token_start_index] != '%')
		tk_params->fmt_index += tk_params->txt_or_arg_len;
	else if (fmt[token_start_index] == '%')
		tk_params->fmt_index += 2;
	tk_params->tk_index++;
}
