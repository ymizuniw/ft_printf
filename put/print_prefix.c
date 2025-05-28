/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:23:31 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/27 17:38:02 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	print_prefix(int n, t_format f)
{
	if (n < 0)
	{
		buffer_write_char(buf, '-');
		return (1);
	}
	else if (f.flag_plus)
	{
		buffer_write_char(buf, '+');
		return (1);
	}
	else if (f.flag_space)
	{
		buffer_write_char(buf, ' ');
		return (1);
	}
	return (0);
}
