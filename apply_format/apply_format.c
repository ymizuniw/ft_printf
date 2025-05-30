/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:18:35 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/30 22:24:27 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static t_bool	set_lens(t_lens *lens, t_format *f, char *prefix, char *sign);
static char		*apply_precision(t_format *f, char *arg, t_lens lens);

char	*apply_format(t_token token, t_format *f)
{
	char	prefix[2];
	char	*sign;
	t_lens	lens;
	char	*precised_arg;
	char	*padding;
	char	*output_str;

	precised_arg = apply_precision(f, token->parsed_arg, lens);
	if (!precised_arg)
		return (NULL);
	output_str = malloc(lens.total + lens.pad + 1);
	if (!output_str)
		return (free(precised_arg), NULL);
	set_output_str(output_str, (const char *)prefix, lens);
	free(precised_arg);
	return (output_str);
}

static t_bool	set_lens(t_lens *lens, t_format *f, char *prefix, char *sign)
{
	lens.prefix = set_count_prefix(f, prefix);
	lens.sign = count_sign(f, sign);
	lens.arg = ft_strlen((const char *)token->parsed_arg);
	lens.precised = set_count_precision(f, len.arg);
	lens.total = lens.prefix + lens.sign + lens.precised;
	lens.pad = set_count_pad(f, lens);
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
		ft_memset(res, '0', zeros);
		ft_strlcpy(res + zeros, arg, lens.arg + 1);
	}
	return (res);
}
