/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:44:16 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/02 00:26:34 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...)
{
		t_list	*tokens;
		va_list	ap;

		va_start(ap, format);
		tokens = tokenize_format(format, ap);
		if (!tokens)//トークンが存在しない場合は？また、""は対応していたか。
			return (-1);
		if (!parse_args(tokens, ap))
			


// 	// parse arguments
// 	// apply format specifiers
// }
