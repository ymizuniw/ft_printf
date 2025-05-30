/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 02:11:04 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/30 04:53:11 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static	t_token *get_conv_token(const char *fmt, size_t *place);
static	t_token	*get_block_token(const char *fmt, size_t *place);
static	void	free_token(void *token_ptr);

t_list	*tokenize_format(const char *fmt, va_list ap)
{
	t_list	*head;
	t_list	*node;
	t_token	*token;
	size_t	place;

	head = NULL;
	place = 0;
	while (fmt[place])
	{
		if (fmt[place] == '%' && fmt[place + 1] && fmt[place + 1] != '%')
			token = get_conv_token(fmt, &place);
		else
			token = get_block_token(fmt, &place);
		if (!token)
			return (ft_lstclear(&head, free_token), NULL);
		node = ft_lstnew(token);
		if (!node)
			return (free_token(token), ft_lstclear(&head, free_token), NULL);
		ft_lstadd_back(&head, node);
	}
	return (head);
}

static	t_token	*get_block_token(const char *format, size_t *place)
{
	size_t len;
	t_token *token;

	len = 0;
	while (format[*place + len] && format[*place + len] != '%')
		len++;
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = TXT;
	token->block = ft_substr(format + *place, 0, len);
	if (!token->block)
		return (free(token->block), free(token), NULL);
	initialize_format(format);
	return (token);
}

static	t_token	*get_conv_token(const char *fmt, size_t *place)
{
	t_token	*token;
	t_format *f;
	size_t start;
	size_t i;

	start = *place;
	i = start + 1;
	token = alloc_token();
	if (!token)
		return (NULL);
	token->type = CONV;
	f = token->format;

	parse_flags(fmt, f, (size_t *)i);
	parse_width(fmt, f, (size_t *)i);
	parse_precision(fmt, f, (size_t *)i);
	parse_specifier(fmt, token, f, (size_t *)i);

}

static void free_token(void *ptr)
{
	t_token *token;

	token = (void *)ptr;
	if (!token)
		return ;
	free(token->block);
	free(token->format);
	free(token);
}

static void initialize_format(t_format *fmt)
{
	fmt->flag_minus = 0;
	fmt->flag_zero = 0;
	fmt->flag_hash = 0;
	fmt->flag_plus = 0;
	fmt->flag_space = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->precision_on = 0;
	fmt->spec = 0;
}
