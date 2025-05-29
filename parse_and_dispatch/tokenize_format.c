/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 03:28:34 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/28 18:08:16 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static void	get_conv_token(const char *fmt, t_token *tokens, va_list ap,
		size_t *place);
static void	get_txt_token(const char *fmt, t_token *tokens, size_t *place);

t_list	*tokenize_format(const char *fmt, va_list ap)
{
	t_list	*head = NULL;
	t_token	*token;
	t_list	*node;

	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) != '%')
			token = get_conv_token(&fmt, ap);
		else
			token = get_txt_token(&fmt);
		if (!token)
			return (ft_lstclear(&head, free_token), NULL);
		node = ft_lstnew(token);
		if (!node)
			return (free_token(token), ft_lstclear(&head, free_token), NULL);
		ft_lstadd_back(&head, node);
	}
	return head;
}

static void	get_conv_token(const char *fmt, t_token *tokens, va_list ap,
		size_t *place)
{

}

static void	get_txt_token(const char *fmt, t_token *tokens, size_t *place)
{
	size_t	len;

	len = 0;
	while (fmt[len] && fmt[len] != '%')
		len++;
	tokens->type = TK_TEXT;
	tokens->str = ft_substr(fmt, 0, len);
	*place += len;
}

static void	free_token(t_token *token)
{
	if (!token)
		return ;
	free(token->str);
	if (token->type == TK_CONV)
		free(token->format);
	free(token);
}
