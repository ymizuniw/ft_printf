/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 04:12:26 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/30 04:45:35 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	parse_width(const char *fmt, t_format *f, size_t *i)
{
	if (fmt[*i] == '*')
	{
		f->width_from_arg = 1;
		(*i)++;
	}
	else if (is_digit(fmt[*i]))
	{
		f->width = ft_atoi(fmt + *i);
		while (is_digit(fmt[*i]))
			i++;
	}
}
