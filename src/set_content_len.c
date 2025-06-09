/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_content_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:59:26 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/09 17:48:20 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_token_content_len(const char *token_start, va_list aq)
{
	int		index;
	int		ret_len;
	char	*arg;
	char	spec;

	index = 0;
	if (token_start[index] && token_start[index] != '%')
	{
		while (token_start[index] && token_start[index] != '%')
			index++;
		return (index);
	}
	else if (token_start[index] == '%' && ft_is_spec(token_start[index + 1]))
	{
		index++;
		spec = token_start[index];
		arg = arg_to_ascii(spec, aq);
		if (!arg)
			return (ft_putstr_fd("invalid argment.", 1), -1);
		ret_len = ft_strlen(arg);
		if (ret_len < 0)
			return (free(arg), -1);
		return (free(arg), ret_len);
	}
	else
		return (-1);
}

int	set_content_len(const char *fmt, t_tk_params *tk_params, va_list aq)
{
	tk_params->txt_or_arg_len = get_token_content_len(fmt
			+ tk_params->fmt_index, aq);
	if (tk_params->txt_or_arg_len < 0)
		return (ft_putstr_fd("failed to get content\n", 1), -1);
	return (1);
}
