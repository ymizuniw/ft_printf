/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flag_conflict.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:00:57 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/31 14:22:19 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	manage_flag_conflict(t_format *f)
{
	if (f->precision_on)
		f->flag_zero = FALSE;
	if (f->flag_plus)
		f->flag_space = FALSE;
	if (f->flag_minus)
		f->flag_zero = FALSE;
	if (!(f->spec == 'x' || f->spec == 'X'))
		f->flag_hash = FALSE;
	if (f->flag_hash)
	{
		f->flag_plus = FALSE;
		f->flag_space = FALSE;
	}
}
