/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 04:02:36 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/31 15:30:04 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	parse_flags(const char *fmt, t_format *f, size_t *place)
{
	while (is_flag(fmt[*place]))
	{
		if (fmt[*place] == '-')
			f->flag_minus = TRUE;
		else if (fmt[*place] == '+')
			f->flag_plus = TRUE;
		else if (fmt[*place] == ' ')
			f->flag_space = TRUE;
		else if (fmt[*place] == '0')
			f->flag_zero = TRUE;
		else if (fmt[*place] == '#')
			f->flag_hash = TRUE;
		(*place)++;
	}
}
