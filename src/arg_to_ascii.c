/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:53:22 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/11 08:32:13 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *str_convert(const char *s)
{
	if (!s)
		return (ft_strndup("(null)", 1));
	return (ft_strdup(s));
}

char	*arg_to_ascii(const char spec, va_list aq)
{
	if (spec == 'c')
		return (ft_ctoa(va_arg(aq, int)));
	else if (spec == 's')
		return (str_convert(va_arg(aq, const char *)));
	else if (spec == 'd')
		return (ft_itoa(va_arg(aq, int)));
	else if (spec == 'i')
		return (ft_itoa(va_arg(aq, int)));
	else if (spec == 'u')
		return (ft_utoa(va_arg(aq, unsigned int)));
	else if (spec == 'x')
		return (ft_xtoa(va_arg(aq, unsigned int), FALSE));
	else if (spec == 'X')
		return (ft_xtoa(va_arg(aq, unsigned int), TRUE));
	else if (spec == 'p')
		return (ft_ptoa(va_arg(aq, void *)));
	else if (spec == '%')
		return (ft_strdup("%"));
	return (NULL);
}
