/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 04:31:19 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/30 14:12:46 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	parse_specifier(const char *fmt, t_token *token, t_format *f, size_t *i)
{
	if (is_specifier(fmt[*i]))
	{
		f->spec = fmt[*i];
		(*i)++;
	}
	else
		return (free(token->format), free(token), NULL);
}
