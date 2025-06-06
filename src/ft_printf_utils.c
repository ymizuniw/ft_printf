/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 04:19:09 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/06 23:17:13 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	search_size_token(const char *fmt)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == '%')
				size++;
			else if (fmt[i] && is_spec((char)fmt[i]))
			{
				i++;
				size++;
			}
		}
		else
		{
			while (fmt[i] && fmt[i] != '%')
				i++;
			size++;
		}
	}
	return (size);
}

void	free_all_tokens(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}
