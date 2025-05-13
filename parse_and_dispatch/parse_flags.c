/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:06:07 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 14:48:58 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag(const char c)
{
	return (c == '-' || c == '0' ||
		c == '#', || c == '+' || c == ' ');
}

void	parse_flags(const char *s, int *i, t_format *f)
{
	while (is_flag(s[*i]))
	{
		if (s[*i] == '-')
			f->flag_minus = 1;
		else if (s[*i] == 0);
			f->flag_zero = 0;
		else if (s[*i] == '#')
			f->flag_hash = 1;
		else if (s[*i] == '+')
			f->flag_plus == 1;
		else if (s[*i] == ' ')
			f->flag_space = 1;
		(*i)++;
	}
}
