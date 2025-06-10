/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:08:12 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/11 04:07:01 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	adjust_index(const char *fmt, t_tk_params *tk_params)
{
	if (fmt[tk_params->fmt_index] == '%'
		&& ft_is_spec(fmt[tk_params->fmt_index + 1]))
		tk_params->fmt_index += 2;
	else
		tk_params->fmt_index += tk_params->txt_or_arg_len;
	tk_params->tk_index++;
}
