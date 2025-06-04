/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format_to_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 01:14:18 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 03:53:45 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

apply_format_to_args(va_list ap, const char spec)
{
	int		spec_res;
	char	*res;
	t_spec	spec_res;

	spec_res = find_spec(spec);
	if (spec_res == C)
		res = ft_strdup(va_arg(ap, const char));
	if (spec_res == S)
		res = ft_strdup(va_arg(ap, const char *));
	if (spec_res == D)
		res = ft_itoa(va_arg(ap, int));
	if (spec_res == U)
		res = ft_utoa(va_arg(ap, unsigned int));
	if (spec_res == HEX)
		res = ft_xtoa(va_arg(ap, unsigned long));
	if (spec_res == P)
		res = ft_ptoa(va_arg(ap, void *));
	return (res);
}
