/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:25:41 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/31 15:27:40 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#');
}

int	is_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x'
		|| c == 'X' || c == '%');
}

t_token	*initialize_token(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->block = NULL;
	token->format = malloc(sizeof(t_format));
	if (!token->format)
		return (free(token), NULL);
	init_format(token->format);
	return (token);
}
