/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_output_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:03:38 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/31 15:45:17 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	set_output_str(char *output_str, t_parts_out parts, t_lens lens)
{
	size_t	buf_index;

	buf_index = 0;
	prefix_output(output_str, (size_t *)buf_index, lens);
	args_output(output_str, (size_t *)buf_index, lens);
	outpu_str[buf_index] = '\0';
}

static void	prefix_output(char *output_str, size_t *buf_index,
		t_parts_out parts, t_lens lens)
{
	if (lens.pad_pos == FRONT)
	{
		ft_memset(output_str + buf_index, ' ', lens.pad);
		buf_index += lens.pad;
	}
	if (lens.prefix)
	{
		ft_memcpy(output_str + buf_index, parts.prefix, lens.prefix);
		buf_index += lens.prefix;
	}
	if (lens.sign)
	{
		ft_memcpy(output_str + buf_index, parts.sign, lens.sign);
		buf_index += lens.sign;
	}
}

static void	args_output(char *output_str, size_t *buf_index, t_parts_out parts,
		t_lens lens)
{
	if (lens.pad_pos == MIDDLE)
	{
		ft_memset(output_str + buf_index, '0', lens.pad);
		buf_index += lens.pad;
	}
	ft_memcpy(output_str + buf_index, parts->precised_arg, lens.precised);
	buf_index += lens.precised;
	if (lens.pad_pos == BACK)
	{
		ft_memset(output_str + buf_index, ' ', lens.pad);
		buf_index += lens.pad;
	}
}
