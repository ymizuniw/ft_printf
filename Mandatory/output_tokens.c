/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 01:14:24 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 04:18:10 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	output_tokens(char **tokens, int token_array_size)
{
	int	i;
	int	out_len;

	i = 0;
	out_len = 0;
	if (!tokens)
		return (-1);
	while (i < token_array_size && token[i])
	{
		out_len += write(1, tokens[i], ft_strlen(tokens[i]));
		i++;
	}
	return (out_len);
}
