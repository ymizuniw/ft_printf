/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_output_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 01:14:30 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/06 23:18:31 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	free_from_error_tokens(size_t t_index, char **token)
{
	while (t_index > 0)
		free(token[--t_index]);
	free(token);
}

// char	**set_output_tokens(va_list ap, const char *fmt,
// 		size_t token_array_size)
// {
// 	size_t	t_index;
// 	char	*tmp_token;
// 	char	**token;
// 	size_t	i;

// 	token = malloc(sizeof(char *) * token_array_size);
// 	if (!token)
// 		return (NULL);
// 	t_index = 0;
// 	i = 0;
// 	while (fmt[i])
// 	{
// 		tmp_token = get_tmp_token(fmt, &i, ap);
// 		if (!tmp_token)
// 		{
// 			free_from_error_tokens(t_index, token);
// 			return (NULL);
// 		}
// 		token[t_index++] = tmp_token;
// 		i++;
// 	}
// 	return (token);
// }

char	**set_output_tokens(va_list ap, const char *fmt,
		size_t token_array_size)
{
	size_t	t_index;
	char	*tmp_token;
	char	**token;
	size_t	i;

	token = malloc(sizeof(char *) * (token_array_size + 1));
	if (!token)
		return (NULL);
	token[token_array_size] = NULL;

	t_index = 0;
	i = 0;
	while (fmt[i])
	{
		tmp_token = get_tmp_token(fmt, &i, ap);
		if (!tmp_token)
		{
			free_from_error_tokens(t_index, token);
			return (NULL);
		}
		token[t_index++] = tmp_token;
	}
	return (token);
}
