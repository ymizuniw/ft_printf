/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:44:14 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 16:42:16 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static t_spec_group	get_spec_group(char c);
static int	dispatch_string_format(const t_token *token, va_list args);
static int	dispatch_number_format(const t_token *token, va_list args);
static int	dispatch_pointer_format(const t_token *token, va_list args);

int	dispatch_format_token(const t_token *token, va_list args)
{
	t_spec_group	group;

	group = get_spec_group(token->format->spec);
	if (group == GR_STRING)
		return (dispatch_string_format(token, args));
	else if (group == GR_NUMBER)
		return (dispatch_number_format(token, args));
	if (group == GR_POINTER)
		return (dispatch_pointer_format(token, args));
	return (0);
}


static t_spec_group	get_spec_group(char c)
{
	if (c == 'c' || c == 's' || c == '%')
		return (GR_STRING);
	else if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (GR_NUMBER);
	else if (c == 'p')
		return (GR_POINTER);
	return (GR_NON);
}

static int	dispatch_string_format(const t_token *token, va_list args)
{
	t_format	*f;

	f = token->format;
	if (f->spec == 'c')
		put_char_format(va_arg(args, int), f);
	else if (f->spec == 's')
		put_str_format(va_arg(args, char *), f);
	else if (f->spec == '%')
		put_percent_format(f);
	return (1);
}

static int	dispatch_number_format(const t_token *token, va_list args)
{
	t_format	*f;

	f = token->format;
	if (f->spec == 'd' || f->spec == 'i')
		apply_format_int(va_arg(args, int), f);
	if (f->spec == 'u')
		apply_format_unsigned(va_arg(args, unsigned int), f);
	if (f->spec == 'x' || f->spec == 'X')
		apply_format_hex(va_arg(args, unsigned int), f, f->spec == 'X');
	return (1);
}

static int	dispatch_pointer_format(const t_token *token, va_list args)
{
	t_format	*f;

	f = token->format;
	if (f->spec == 'p')
		apply_format_ptr(va_arg(args, void *), f);
	return (1);
}
