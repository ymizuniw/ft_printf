/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 04:25:57 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/31 13:41:33 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	parse_precision(const char *fmt, t_format *f, size_t *place)
{
	if (fmt[*place] == '.')
	{
		f->precision = TRUE;
		(*place)++;
		if (fmt[*place] == '*')
		{
			f->prec_from_arg = TRUE;
			(*place)++;
		}
		else if (ft_is_digit(fmt[*place]))
		{
			f->precision = ft_atoi(fmt + *place);
			while (ft_is_digit(fmt[*place]))
				(*place)++;
		}
		else
			f->precision_on = FALSE;
	}
}
