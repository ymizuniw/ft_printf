/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 05:11:00 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/30 22:38:57 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	parse_args(t_list *tokens, va_list ap)
{
	t_token		*token;
	t_format	*f;

	while (tokens)
	{
		token = tokens->content;
		if (token->type == CONV)
		{
			f = token->format;
			if (f->width_from_arg)
				f->width = va_arg(ap, int);
			if (f->prec_from_arg)
				f->precision = va_arg(ap, int);
		}
		token->parsed_arg = arg_to_spec(f, ap);
		tokens = tokens->next;
	}
}

static char	*arg_to_spec(t_format *f, va_list ap)
{
	int		arg;
	void	*ptr;
	char	*str;

	if (!f || !ap)
		return (NULL);
	if (f->spec == 'd' || f->spec == 'i')
	{
		arg = va_arg(*ap, int);
		if (arg < 0)
			f->is_negative = TRUE;
		return (ft_itoa_abs(arg));
	}
	if (f->spec == 'u')
		return (ft_uitoa(va_arg(*ap, unsigned int)));
	if (f->spec == 'x' || f->spec == 'X')
		return (ft_xtoa(va_arg(*ap, unsigned int), f->spec == 'X'));
	if (f->spec == 'c')
		return (ft_ctoa(va_arg(*ap, int)));
	if (f->spec == 's' || f->spec == 'p')
		return (s_or_p(f, ap));
	if (f->spec == '%')
		return (ft_strdup("%"));
	return (NULL);
}

static char	*s_or_p(t_format f, va_list *ap)
{
	char	*str;

	void *ptr
	if (f->spec == 's')
	{
		str = va_arg(*ap, char *);
		if (!str)
			return (ft_strdup("(null)"));
		return (ft_strdup(str));
	}
	else if (f->spec == 'p')
	{
		ptr = va_arg(*ap, void *);
		if (!ptr)
			return (ft_ptoa(ptr));
	}
	return (NULL);
}
