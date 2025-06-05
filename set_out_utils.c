/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_out_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 03:34:28 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 14:51:06 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	ft_is_upper(const char c)
{
	return (c == 'X');
}

int	is_spec(const char c)
{
	return ((c == 'c') || (c == 's') || (c == 'd') || (c == 'i') || (c == 'u')
		|| (c == 'x' || c == 'X') || (c == 'p'));
}

t_spec	find_spec(const char c)
{
	if (c == 'c')
		return (C);
	else if (c == 's')
		return (S);
	else if (c == 'd')
		return (D);
	else if (c == 'i')
		return (D);
	else if (c == 'u')
		return (U);
	else if (c == 'x' || c == 'X')
		return (HEX);
	else if (c == 'p')
		return (P);
	else
		return (0);
}

char	*get_tmp_token(const char *fmt, size_t *i, va_list ap)
{
	char	*tmp_token;
	size_t	txt_len;

	// if (!(*fmt) || !i)
	// 	return (NULL);
	if (fmt[*i] == '%')
	{
		(*i)++;
		if (fmt[*i] && fmt[*i] == '%')
			tmp_token = ft_strndup("%", 1);
		else if (fmt[*i] && is_spec(fmt[*i]))
			tmp_token = apply_format_to_args(ap, fmt[*i]);
		else
			return (NULL);
	}
	else
	{
		txt_len = 0;
		while (fmt[*i] && fmt[*i] != '%')
			txt_len++;
		tmp_token = ft_strndup(fmt + (*i), txt_len);
		(*i) += txt_len - 1;
	}
	return (tmp_token);
}

char	*ft_strndup(const char *str, size_t n)
{
	size_t	len;
	char	*res;

	if (!str)
		return (NULL);
	len = 0;
	while (*str && len < n)
		len++;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (--len > 0)
		res[len] = str[len];
	res[len] = '\0';
	return (res);
}
