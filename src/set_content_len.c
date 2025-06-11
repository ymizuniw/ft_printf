/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_content_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:59:26 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/11 16:10:34 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	txt_token_len(const char *fmt, int *local_index)
{
	while (fmt[*local_index] && fmt[*local_index] != '%')
		(*local_index)++;
	return (*local_index);
}

static int	conv_token_len(const char *fmt, int *local_index, va_list aq)
{
	char	*arg;
	char	spec;
	int		ret_len;

	(*local_index)++;
	spec = fmt[*local_index];
	if (spec == '%')
		return (1);
	arg = arg_to_ascii(spec, aq);
	if (!arg)
		return (ft_putstr_fd("invalid argment.", 1), -1);
	else
		ret_len = ft_strlen(arg);
	if (ret_len < 0)
		return (free(arg), -1);
	return (free(arg), ret_len);
}

static int	get_token_content_len(const char *fmt, va_list aq)
{
	int	local_index;
	int	ret_len;

	local_index = 0;
	ret_len = 0;
	if (fmt[local_index] != '%')
		return (txt_token_len(fmt, &local_index));
	else if (fmt[local_index] == '%' && ft_is_spec(fmt[local_index + 1]))
		return (conv_token_len(fmt, &local_index, aq));
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
