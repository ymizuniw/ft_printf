/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prob_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 00:09:25 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 00:30:04 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
// #include "prob_malloc.h"
#include <stdio.h>
#include <time.h>

void *prob_malloc(size_t size)
{
	if (rand() < (RAND_MAX / 1000))
	{
		fprintf(stderr, "malloc failed\n");
		return NULL;
	}
	return malloc(size);
}
