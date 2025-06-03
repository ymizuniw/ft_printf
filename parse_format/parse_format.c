/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:53:08 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/04 01:27:59 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	parse_format(const char *fmt, t_token *token, t_format *f,
		size_t *place)
{
	parse_flags(fmt, f, place);
	parse_width(fmt, f, place);
	parse_precision(fmt, f, place);
	if (!parse_specifier(fmt, f, place))
	{
		printf("parse_specifier failed at pos %zu: '%c'\n", *place, fmt[*place]);
		free_token(token);
		return ;
	}
	manage_flag_spec(f);
	manage_flag_conflict(f);
	printf("format char is '%c'\n", f->spec);
}
