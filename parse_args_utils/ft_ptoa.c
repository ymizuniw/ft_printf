/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:33:00 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/30 22:40:09 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h> // uintptr_t


char	*ptoa(void *ptr)
{
	char			*hex;
	unsigned long	addr;
	char			*result;
	size_t			len;

	if (!ptr)
		return (ft_strdup("(nil)"));

	addr = (unsigned long)ptr;
	hex = xtoa(addr, 0);
	if (!hex)
		return (NULL);

	len = ft_strlen(hex) + 2;
	result = malloc(len + 1);
	if (!result)
		return (free(hex), NULL);

	result[0] = '0';
	result[1] = 'x';
	ft_memcpy(result + 2, hex, len - 2);
	result[len] = '\0';
	free(hex);
	return (result);
}
