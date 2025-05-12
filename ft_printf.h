/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:08:08 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/12 20:58:17 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	struct	s_format
{
	int		flag_minus;
	int		flag_zero;
	int		flag_hash;
	int		flag_plus;
	int		flag_space;
	int		width;
	int		precision;
	int		precision_on;
	char	specifier;
}	t_format;
//width is the min len of field. ex)%10d -> 10.
//precision is the max len of field or min digits of num.
//precision_on is flag to the appearance of ".".
//specifier is format designator.
//'-' will be prioritized to 0, when flag zero and minus exist.

#define	PRINTF_BUF_SIZE 1024
//we never use _IO_FILE struct on this project,
//because it leads to be pritf's buf management.

typedef	struct s_buffer
{
	char 	data[PRINTF_BUF_SIZE];
	int		len;
	int		total;
}	t_buffer;
