/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:44:16 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/03 02:13:35 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	t_list	*head;
	size_t	tmp_len;
	size_t	total_len;
	va_list	ap;

	tmp_len = 0;
	total_len = 0;
	va_start(ap, format);
	head = tokenize_format(format);
	if (!head)
	{
		va_end(ap);
		if(format && format[0] != '\0')
			return (-1);
		return (0);
	}
	if (!parse_args(head, ap))
	{
		va_end(ap);
		return (-1);
	}
	output_list(head, &total_len);
	if (output_list(head, &total_len) < 0)
{
	ft_lstclear(&head, free_token);
	va_end(ap);
	return (-1);
}
	tmp_len = total_len;
	if (tmp_len > total_len)
	{
		va_end(ap);
		return (-1);
	}
	va_end(ap);
	return (total_len);
}
