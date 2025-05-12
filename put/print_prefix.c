/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:23:31 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/12 23:31:06 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_prefix(int n, t_format f, t_buffer *buf)
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
