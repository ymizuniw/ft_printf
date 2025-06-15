/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flag_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:19:41 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/13 13:37:50 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	manage_char_spec(t_format *f);

void	manage_flag_spec(t_format *f)
{
	if (f->spec == '%')
	{
		f->width = 0;
		f->precision = 0;
	}
	if (f->spec == 'p')
	{
		f->flag_plus = FALSE;
		f->flag_space = FALSE;
		f->flag_hash = FALSE;
	}
	else if (f->spec == 'c' || f->spec == 's')
		manage_char_spec(f);
	else if (is_num_spec(f->spec))
	{
		if (f->flag_plus && f->flag_space)
			f->flag_space = FALSE;
		if (f->precision_on)
			f->flag_zero = FALSE;
	}
}

static void	manage_char_spec(t_format *f)
{
	if (f->spec == 's' && f->precision_on && f->precision == 0)
		f->flag_minus = FALSE;
	f->flag_plus = FALSE;
	f->flag_space = FALSE;
	f->flag_hash = FALSE;
	f->flag_zero = FALSE;
}
