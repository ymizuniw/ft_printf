/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 04:55:29 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/09 12:30:53 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int		out_len;
	int		token_array_size;
	int		tk_index;
	int		txt_or_arg_len;
	int		fmt_index;
	int		count_out_tokens;
	char	**tokens;
	// char	*tmp_tokens_malloc;
	char 	*tmp_token_content;
	int		token_start_index;
	va_list	ap;
	va_list	aq;

	va_start(ap, fmt);
	va_copy(aq, ap);
	if (!fmt)
	{
		ft_putstr_fd("(null)", 1);
		return (-1);
	}
	token_array_size = get_token_array_size(fmt);
	if (token_array_size < 0)
	{
		ft_putstr_fd("invalid format", 1);
		return (-1);
	}
	tokens = (char **)malloc(sizeof(char *) * token_array_size);
	if (!tokens)
		return (ft_putstr_fd("malloc for tokens failed", 1), -1);
	tk_index = 0;
	txt_or_arg_len = 0;
	fmt_index = 0;
	while (tk_index < token_array_size)
	{
		token_start_index = fmt_index;
		txt_or_arg_len = get_token_content_len(fmt + fmt_index, aq);
		if (txt_or_arg_len < 0)
			return (ft_putstr_fd("failed to get content\n", 1), -1);
		tmp_token_content = get_token_content(fmt, fmt_index, txt_or_arg_len,
				ap);
		if (!tmp_token_content)
		{
			get_token_error_free(tokens, tk_index);
			return (ft_putstr_fd("getting token content failed.", 1), -1);
		}
		tokens[tk_index] = tmp_token_content;
		if (fmt[token_start_index] != '%')
			fmt_index += txt_or_arg_len;
		else if (fmt[token_start_index] == '%')
			fmt_index += 2;
		tk_index++;
	}
	out_len = 0;
	count_out_tokens = 0;
	while (token_array_size > count_out_tokens)
	{
		out_len += print_token(tokens[count_out_tokens]);
		if (out_len < 0)
			return (get_token_error_free(tokens, count_out_tokens), ft_putstr_fd("output failed", 1), -1);
		count_out_tokens++;
	}
	destruct_tokens(tokens, token_array_size);
	va_end(aq);
	va_end(ap);
	return (out_len);
}

void	destruct_tokens(char **tokens, int token_array_size)
{
	int count;

	count = 0;
	while (count < token_array_size)
	{
		free(tokens[count]);
		count++;
	}
	free(tokens);
}

int	print_token(char *token_unit)
{
	return (write(1, token_unit, ft_strlen(token_unit)));
}

char	*ft_strndup(const char *src, size_t n)
{
	size_t	count;
	char	*res;

	if (!src)
		return (NULL);
	res = malloc(n + 1);
	count = 0;
	while (count < n)
	{
		res[count] = src[count];
		count++;
	}
	res[n] = '\0';
	return (res);
}

char	*get_token_content(const char *fmt, int fmt_index, int txt_or_arg_len,
		va_list ap)
{
	char	*arg;
	char	spec;

	if (fmt[fmt_index] && fmt[fmt_index] != '%')
		return (ft_strndup(fmt, (size_t)txt_or_arg_len));
	else if (fmt[fmt_index] == '%' && ft_is_spec(fmt[fmt_index + 1]))
	{
		spec = fmt[fmt_index + 1];
		arg = arg_to_ascii(spec, ap);
		if (!arg)
		{
			return (ft_strndup("(null)", 6));
		}
		return (arg);
	}
	else
		return (NULL);
}

void	get_token_error_free(char **tokens, int tk_index)
{
	int	i;

	i = --tk_index;
	while (i > 0)
	{
		if (!tokens[i])
			break ;
		free(tokens[i--]);
	}
	free(tokens);
}

int	get_token_content_len(const char *token_start, va_list aq)
{
	int		index;
	int		ret_len;
	char	*arg;
	char	spec;

	index = 0;
	if (token_start[index] && token_start[index] != '%')
	{
		while (token_start[index] && token_start[index] != '%')
			index++;
		return (index);
	}
	else if (token_start[index] == '%' && ft_is_spec(token_start[index + 1]))
	{
		index++;
		spec = token_start[index];
		arg = arg_to_ascii(spec, aq);
		if (!arg)
			return (ft_putstr_fd("invalid argment.", 1), -1);
		ret_len = ft_strlen(arg);
		if (ret_len < 0)
			return (free(arg), -1);
		return (free(arg), ret_len);
	}
	else
		return (-1);
}

char	*arg_to_ascii(const char spec, va_list aq)
{
	if (spec == 'c')
		return (ft_ctoa(va_arg(aq, int)));
	else if (spec == 's')
		return (ft_strdup(va_arg(aq, const char *)));
	else if (spec == 'd')
		return (ft_itoa(va_arg(aq, int)));
	else if (spec == 'i')
		return (ft_itoa(va_arg(aq, int)));
	else if (spec == 'u')
		return (ft_utoa(va_arg(aq, unsigned int)));
	else if (spec == 'x')
		return (ft_xtoa(va_arg(aq, unsigned long), FALSE));
	else if (spec == 'X')
		return (ft_xtoa(va_arg(aq, unsigned long), TRUE));
	else if (spec == 'p')
		return (ft_ptoa(va_arg(aq, void *)));
	else if (spec == '%')
		return (ft_strdup("%"));
	return (NULL);
}

int	get_token_array_size(const char *fmt)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (fmt[i])
	{
		if (fmt[i] && fmt[i] != '%')
		{
			while (fmt[i] && fmt[i] != '%')
				i++;
			size++;
		}
		else if (fmt[i] == '%' && ft_is_spec(fmt[i + 1]))
		{
			i += 2;
			size++;
		}
		else
			return (-1);
	}
	return (size);
}

t_bool	ft_is_spec(const char c)
{
	return (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x'
		|| c == 'X' || c == 'p' || c == '%');
}
