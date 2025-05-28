/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nchar_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:47:48 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/27 21:52:00 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int put_nchar_buf(char *dst, char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		dst[i] = c;
		i++;
	}
	return i;
}

int put_prefix_buf(char *dst, int n, t_format f)
{
	if (n < 0)
	{
		*dst = '-';
		return (1);
	}
	else if (f.flag_plus)
	{
		*dst = '+';
		return (1);
	}
	else if (f.flag_space)
	{
		*dst = ' ';
		return (1);
	}
	else if (f.flag_space)
	{
		*dst = ' ';
		return (1);
	}
	return (0);
}
