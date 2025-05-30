/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 04:25:57 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/30 20:43:52 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	parse_precision(const char *fmt, t_format *f, size_t *i)
{
	if (fmt[*i] == '.')
	{
		f->precision = TRUE;
		(*i)++;
		if (fmt[*i] == '*')
		{
			f->prec_from_arg = TRUE;
			(*i)++;
		}
		else if (is_digit(fmt[*i]))
		{
			f->precision = ft_atoi(fmt + *i);
			while (is_digit(fmt[*i]))
				(*i)++;
		}
		else
			f->precision_on = FALSE;
	}
}
