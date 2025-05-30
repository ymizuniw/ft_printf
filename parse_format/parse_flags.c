/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 04:02:36 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/30 04:46:12 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	parse_flags(const char *fmt, t_format *f, size_t *i)
{
	size_t	index;

	while (is_flag(fmt[*i]))
	{
		if (fmt[*i] == '-')
			f->flag_minus = TRUE;
		else if (fmt[*i] == '+')
			f->flag_plus = TRUE;
		else if (fmt[*i] == ' ')
			f->flag_space = TRUE;
		else if (fmt[*i] == '0')
			f->flag_zero = TRUE;
		else if (fmt[*i] == '#')
			f->flag_hash = TRUE;
	}
}
