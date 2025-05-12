/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:40:19 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/12 15:51:41 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_format	parse_format(const char *s, int *i, va_list args)
{
	t_format	f;

	ft_memset(&f, 0, sizeof(t_format));
	parse_flags(s, i, &f);	//i -> ?
	parse_width(s, i, &f, args); //?
	parse_precision(s, i, &f, args); //?
	f.specifier = s[*i];
	return (f);
}
