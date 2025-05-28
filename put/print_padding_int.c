/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:31:38 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/27 17:36:31 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	print_padding_int(t_format f, int len, int has_prefix)
{
	int		total_len;
	int		padding_len;
	char	padding_char;

	padding_char = ' ';
	if (f.flag_zero && !f.flag_minus && !f.precision_on)
		padding_char = '0';
	total_len = len + has_prefix;
	if (f.precision_on && f.precision > len)
		total_len = f.precision + has_prefix;
	padding_len = f.width - total_len;
	if (padding_len < 0)
		padding_len = 0;
	return ()
}
