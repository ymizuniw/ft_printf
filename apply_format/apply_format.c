/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:18:35 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/31 15:22:29 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static t_bool	set_lens(t_lens *lens, t_format *f, char *prefix, char *sign);
static char		*apply_precision(t_format *f, char *arg, t_lens lens);

char	*apply_format(t_token *token, t_format *f)
{
	t_parts_out	parts;
	t_lens		lens;
	char		*output_str;

	parts.precised_arg = apply_precision(f, token->parsed_arg, lens);
	if (!parts.precised_arg)
		return (NULL);
	output_str = malloc(lens.total + lens.pad + 1);
	if (!output_str)
		return (free(parts.precised_arg), NULL);
	set_output_str(output_str, (const char *)parts.prefix, lens);
	free(parts.precised_arg);
	return (output_str);
}

static t_bool	set_lens(t_lens *lens, t_format *f, t_parts_out parts)
{
	lens.prefix = set_count_prefix(f, parts.prefix);
	lens.sign = count_sign(f, parts.sign);
	lens.arg = ft_strlen((const char *)token->parsed_arg);
	lens.precised = set_count_precision(f, len.arg);
	lens.total = lens.prefix + lens.sign + lens.precised;
	lens.pad = set_count_pad(f, lens);
	parts.prefix_len = lens.prefix;
	parts.sign_len = lens.sign;
	parts.precised_len = lens.precised;
	parts.padding_len = lens.padding;
	return (TRUE);
}

static char	*apply_precision(t_format *f, char *arg, t_lens lens)
{
	char	*res;
	size_t	num_zeros;

	res = malloc(lens.precised + 1);
	if (!res)
		return (NULL);
	if (f->spec == 's')
		ft_strlcpy(res, arg, lens.precised + 1);
	else
	{
		num_zeros = lens.precised - lens.arg;
		ft_memset(res, '0', num_zeros);
		ft_strlcpy(res + num_zeros, arg, lens.arg + 1);
	}
	return (res);
}
