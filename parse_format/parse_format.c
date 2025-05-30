/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:53:08 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/30 14:12:30 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	parse_format(const char *fmt, t_token *token, t_format *f, size_t *i)
{
	parse_flags(fmt, f, (size_t *)i);
	parse_width(fmt, f, (size_t *)i);
	parse_precision(fmt, f, (size_t *)i);
	parse_specifier(fmt, token, f, (size_t *)i);
	manage_flag_conlict(f);
}
