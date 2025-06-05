/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:03:05 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 14:09:44 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	len_address(const char *address_hex)
{
	size_t	len;

	if (!address_hex)
		return (0);
	len = 0;
	while (*address_hex++)
		len++;
	return (len);
}

static void	copy_address(char *res, const char *address_hex, size_t len)
{
	size_t	i;

	i = 0;
	if (!res || !address_hex)
		return ;
	while (i < len)
	{
		res[i + 2] = address_hex[i];
		i++;
	}
}

char	*ft_ptoa(void *ptr)
{
	size_t	address;
	size_t	len;
	char	*address_hex;
	char	*res;

	len = 0;
	address = (size_t)ptr;
	address_hex = ft_xtoa(address, 0);
	if (!address_hex)
		return (NULL);
	len = len_address(address_hex);
	res = malloc(len + 3);
	if (!res)
	{
		free(address_hex);
		return (NULL);
	}
	res[len + 2] = '\0';
	res[0] = '0';
	res[1] = 'x';
	copy_address(res, address_hex, len);
	free(address_hex);
	return (res);
}
