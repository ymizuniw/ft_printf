/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format_to_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 01:14:18 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/06 08:23:17 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *ft_print_str(va_list ap)
{
	char *res;

	if (!va_arg(ap, const char *))
		return (ft_strdup("(null)"));
	res = ft_strdup(va_arg(ap, const char *));
	return (res);
}

char	*apply_format_to_args(va_list ap, const char spec)
{
	char	*res;
	t_spec	spec_res;

	spec_res = find_spec(spec);
	if (spec_res == C)
		res = ft_strdup(va_arg(ap, const char *));
	if (spec_res == S)
		res = ft_print_str(ap);
	if (spec_res == D)
		res = ft_itoa_pf(va_arg(ap, int));
	if (spec_res == U)
		res = ft_utoa(va_arg(ap, unsigned int));
	if (spec_res == HEX)
		res = ft_xtoa(va_arg(ap, unsigned long), ft_is_upper(spec_res));
	if (spec_res == P)
		res = ft_ptoa(va_arg(ap, void *));
	if (!res)
		return (NULL);
	return (res);
}
