/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:13:15 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/09 17:13:38 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	destruct_tokens(char **tokens, int token_array_size)
{
	int	count;

	count = 0;
	while (count < token_array_size)
	{
		free(tokens[count]);
		count++;
	}
	free(tokens);
}
