/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:18:35 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/04 07:32:54 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static t_bool	set_lens(t_lens *lens, t_token *token, t_format *f, t_parts_out *parts);
static char		*apply_precision(t_format *f, char *arg, t_lens *lens);
static void	initialize_len_and_parts(t_lens *lens, t_parts_out *parts);

char	*apply_format(t_token *token, t_format *f)
{
	t_parts_out	parts;
	t_lens		lens;
	char		*output_str;

	token->lens = malloc (sizeof(t_lens));
	if (!token->lens)
		return (NULL);
	initialize_len_and_parts(&lens, &parts);
	set_lens(&lens, token, f, &parts);
	parts.precised_arg = apply_precision(f, token->parsed_arg, &lens);
	if (!parts.precised_arg)
		return (NULL);
	output_str = malloc(lens.total + lens.pad + 1);
	if (!output_str)
		return (free(parts.precised_arg), NULL);
	set_output_str(output_str, &parts, &lens);
	free(parts.precised_arg);
	*(token->lens) = lens;
	return (output_str);
}

static void	initialize_len_and_parts(t_lens *lens, t_parts_out *parts)
{
	lens->prefix = 0;
	lens->sign = 0;
	lens->arg = 0;
	lens->prec = lens->arg;
	lens->total = 0;
	lens->pad = 0;
	parts->prefix_len = 0;
	parts->sign_len = 0;
	parts->prec_len = lens->arg;
	parts->pad_len = 0;
}

static t_bool	set_lens(t_lens *lens, t_token *token, t_format *f, t_parts_out *parts)
{
	lens->prefix = set_count_prefix(f, parts->prefix);
	lens->sign = set_count_sign(f, parts->sign);
	lens->arg = ft_strlen((const char *)token->parsed_arg);
	lens->prec = set_count_precision(f, lens->arg);
	lens->total = lens->prefix + lens->sign + lens->prec;
	lens->pad = set_count_pad(f, lens);
	parts->prefix_len = lens->prefix;
	parts->sign_len = lens->sign;
	parts->prec_len = lens->prec;
	parts->pad_len = lens->pad;
	return (TRUE);
}

static char	*apply_precision(t_format *f, char *arg, t_lens *lens)
{
	char	*res;
	int	num_zeros;

	res = malloc(lens->prec + 1);
	if (!res)
		return (NULL);
	if (f->spec == 's')
		ft_strlcpy(res, arg, lens->prec + 1);
	else
	{
		num_zeros = lens->prec - lens->arg;
		ft_memset(res, '0', num_zeros);
		ft_strlcpy(res + num_zeros, arg, lens->arg + 1);
	}
	return (res);
}
