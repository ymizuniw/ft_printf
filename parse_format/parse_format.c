/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:53:08 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/04 02:49:11 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	parse_format(const char *fmt, t_format *f,
		size_t *place)
{
	parse_flags(fmt, f, place);
	parse_width(fmt, f, place);
	parse_precision(fmt, f, place);
	if (!parse_specifier(fmt, f, place))
	{
		f->spec = 0;
		return ;
	}
	manage_flag_spec(f);
	manage_flag_conflict(f);
	printf("format char is '%c'\n", f->spec);
}
