/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 04:31:19 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/04 06:57:58 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

t_bool	parse_specifier(const char *fmt, t_format *f,
		size_t *place)
{
	if (is_specifier(fmt[*place]))
	{
		f->spec = fmt[*place];
		(*place)++;
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}
