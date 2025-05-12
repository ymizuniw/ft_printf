/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:52:36 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/13 02:57:01 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	apply_format_hex(unsigned int n, t_format f, t_buffer *buf, int upper)
{
	char			num[17];
	const	char	*base;
	int				len;
	int				count;
	int				has_prefix;

	base = (upper) ? "0123456789ABCDEF" : "0123456789abcdef";
	len = utoa_buf(num, (unsigned long)n, base);
	has_prefix = (f.flag_hash && n != 0);
	if (f.precision_on && f.precision == 0 && n == 0)
		len = 0;
	count = 0;
	
}
