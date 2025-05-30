/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_output_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:03:38 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/30 22:24:33 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	set_output_str(char *output_str char *precised_arg, char *sign,
		char *prefix, t_lens lens)
{
	size_t	i;

	i = 0;
	prefix_output(output_str, (size_t *)i, f, lens);
	args_output(output_str, (size_t *)i, f, lens);
	outpu_str[i] = '\0';
}

static void	prefix_output(char *output_str, size_t *i, f_format *f, t_lens lens)
{
	if (lens.pad_pos == FRONT)
	{
		ft_memset(output_str + i, ' ', lens.pad);
		i += lens.pad;
	}
	if (lens.prefix)
	{
		ft_memcpy(output_str + i, prefix, lens.prefix);
		i += lens.prefix;
	}
	if (lens.sign)
	{
		ft_memcpy(output_str + i, sign, lens.sign);
		i += lens.sign;
	}
}

static void	args_output(char *output_str, size_t *i, f_format *f, t_lens lens)
{
	if (lens.pad_pos == MIDDLE)
	{
		ft_memset(output_str + i, '0', lens.pad);
		i += lens.pad;
	}
	ft_memcpy(output_str + i, f->precised_arg, lens.precised);
	i += lens.precised;
	if (lens.pad_pos == BACK)
	{
		ft_memset(output_str + i, ' ', lens.pad);
		i += lens.pad;
	}
}
