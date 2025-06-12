/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 05:11:00 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/11 21:19:07 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*arg_to_spec(t_format *f, va_list ap);
static char	*s_or_p(t_format *f, va_list ap);

t_bool	parse_args(t_list *head, va_list ap)
{
	t_token		*token;
	char		*stash;
	t_format	*f;

	while (head)
	{
		token = head->content;
		if (token->type == CONV)
		{
			f = token->format;
			if (f->width_from_arg)
				f->width = va_arg(ap, int);
			if (f->prec_from_arg)
				f->precision = va_arg(ap, int);
			stash = arg_to_spec(f, ap);
			if (!stash)
				return (FALSE);
			token->parsed_arg = stash;
		}
		head = head->next;
	}
	return (TRUE);
}

static char	*arg_to_spec(t_format *f, va_list ap)
{
	int	arg;

	if (!f)
		return (NULL);
	if (f->spec == 'd' || f->spec == 'i')
	{
		arg = va_arg(ap, int);
		if (arg < 0)
			f->is_negative = TRUE;
		return (ft_itoa_abs(arg));
	}
	if (f->spec == 'u')
		return (ft_utoa(va_arg(ap, unsigned int)));
	if (f->spec == 'x' || f->spec == 'X')
		return (ft_xtoa(va_arg(ap, unsigned int), ft_is_upper(f->spec)));
	if (f->spec == 'c')
		return (ft_ctoa(va_arg(ap, int)));
	if (f->spec == 's' || f->spec == 'p')
		return (s_or_p(f, ap));
	if (f->spec == '%')
		return (ft_strdup("%"));
	return (NULL);
}

static char	*s_or_p(t_format *f, va_list ap)
{
	void	*ptr;
	char	*str;

	if (f->spec == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
			return (ft_strndup("(null)", 6));
		return (ft_strdup(str));
	}
	else if (f->spec == 'p')
	{
		f->flag_hash = FALSE;
		ptr = va_arg(ap, void *);
		if (ptr)
			return (ft_ptoa(ptr));
		else
			return (ft_strndup("(nil)", 5));
	}
	return (NULL);
}
