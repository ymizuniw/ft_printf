/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 02:11:04 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/12 19:53:28 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_token	*get_conv_token(const char *fmt, size_t *place);
static t_token	*get_block_token(const char *fmt, size_t *place);

t_list	*tokenize_format(const char *fmt)
{
	t_list	*head;
	t_list	*node;
	t_token	*token;
	size_t	place;

	head = NULL;
	place = 0;
	while (fmt[place])
	{
		if (fmt[place] == '%' && fmt[place + 1])
		{
			place++;
			token = get_conv_token(fmt, &place);
		}
		else
			token = get_block_token(fmt, &place);
		if (!token)
			return (ft_lstclear(&head, free_token), NULL);
		node = ft_lstnew(token);
		if (!node)
			return (ft_lstclear(&head, free_token), NULL);
		ft_lstadd_back(&head, node);
	}
	return (head);
}

static t_token	*get_block_token(const char *fmt, size_t *place)
{
	size_t	len;
	t_token	*token;

	len = 0;
	while (fmt[*place + len] && fmt[*place + len] != '%')
		len++;
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = TXT;
	token->block = ft_substr(fmt + *place, 0, len);
	token->parsed_arg = NULL;
	token->lens = NULL;
	token->format = NULL;
	if (!token->block)
		return (NULL);
	*place += len;
	return (token);
}

static t_token	*get_conv_token(const char *fmt, size_t *place)
{
	t_token		*token;
	t_format	*f;

	token = initialize_token();
	if (!token)
		return (NULL);
	token->type = CONV;
	f = token->format;
	if (!f)
		return (NULL);
	parse_format(fmt, f, place);
	if (f->spec == 0)
		return (NULL);
	return (token);
}
