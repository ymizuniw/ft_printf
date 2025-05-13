/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:36:20 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 14:34:30 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	parse_precision(const char *s, int *i, t_format *f, va_list args)
{
	if (s[*i] == '-')
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
			while (ft_isdigit(s[*i++]))
			{
				f->precision = f->precision * 10 + (s[*i] - '0');
				(*i)++
			}
	}
}
