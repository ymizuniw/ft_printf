/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:34:35 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 14:40:49 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(const char *s, int *i, t_format f, var_list args)
{
	if (s[*i] == '*')
	{
		f->width = va_arg(args, int);
		if (f->width < 0)
		{
			f->flag_minus = 1;
			f->width *= -1;
		}
		(*i)++;
	}
}
