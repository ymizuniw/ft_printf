/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:25:41 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 23:11:38 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag(const char c)
{
	return (c == '-' || c == '0' || c == '#' || c == '+' || c == ' ');
}

void	parse_flags(const char *s, int *i, t_format *f)
{
	while (is_flag(s[*i]))
	{
		if (s[*i] == '-')
			f->flag_minus = 1;
		else if (s[*i] == '0')
			f->flag_zero = 1;
		else if (s[*i] == '#')
			f->flag_hash = 1;
		else if (s[*i] == '+')
			f->flag_plus = 1;
		else if (s[*i] == ' ')
			f->flag_space = 1;
		(*i)++;
	}
}

void	parse_precision(const char *s, int *i, t_format *f, va_list args)
{
	if (s[*i] == '.')
	{
		f->precision_on = 1;
		f->precision = 0;
		(*i)++;
		if (s[*i] == '*')
		{
			f->precision = va_arg(args, int);
			if (f->precision < 0)
				f->precision_on = 0;
			(*i)++;
		}
		else
			f->width = parse_number(s, i);
	}
}

void	parse_width(const char *s, int *i, t_format *f, va_list args)
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
	else
		f->width = parse_number(s, i);
}

static int	parse_number(const char *s, int *i)
{
	int	result;

	result = 0;
	while (ft_is_digit(s[*i]))
	{
		result = result * 10 + (s[*i] - '0');
		(*i)++;
	}
	return (result);
}
// pointer delegation is used to reflect index shift.
