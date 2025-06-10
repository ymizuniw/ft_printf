/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_error_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:06:57 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/11 04:06:12 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_token_error_free(t_token *tokens, int tk_index)
{
	int	i;

	i = --tk_index;
	while (i > 0)
	{
		if (!tokens[i].content)
			break ;
		free(tokens[i--].content);
	}
	free(tokens);
}
