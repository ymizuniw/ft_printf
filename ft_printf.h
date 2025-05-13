/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:08:08 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/14 03:13:09 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format
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
}			t_format;
// width is the min len of field. ex)%10d -> 10.
// precision is the max len of field or min digits of num.
// precision_on is flag to the appearance of ".".
// specifier is format designator.
//'-' will be prioritized to 0, when flag zero and minus exist.

typedef struct s_buffer
{
	char	*data;
	int		len;
	size_t	total;
	int		capacity;
}			t_buffer;

/*main*/
int			ft_printf(const char *format, ...);

/*parse*/
t_format	parse_format(const char *s, int *i, va_list args);
void		parse_flags(const char *s, int *i, t_format *f);
void		parse_width(const char *s, int *i, t_format *f, va_list args);
void		parse_precision(const char *s, int *i, t_format *f, va_list args);

/*dispatcher*/
int			dispatch_format(const char *s, va_list args, t_buffer *buf);

/*put*/
int			put_char_format(char c, t_format f, t_buffer *buf);
int			put_str_format(char *s, t_format f, t_buffer *buf);
int			put_percent_format(t_format f, t_buffer *buf);

/*apply*/
int			apply_format_int(int n, t_format f, t_buffer *buf);
int			apply_format_unsigned(unsigned int n, t_format f, t_buffer *buf);
int			apply_format_hex(unsigned int n, t_format f, t_buffer *buf,
				int is_upper);
int			apply_format_ptr(void *ptr, t_format f, t_buffer *buf);
int			print_prefix (int n, t_format f, t_buffer *buf);

/*apply_utils*/
int	itoa_buf(char *buf, int n);
int	utoa_buf(char *buf, unsigned int n);
int	utoa_base_buf(char *buf, unsigned long n, const char *base);
int print_padding_int(t_format f, int len, int has_prefix, t_buffer *buf);

/*buffer*/
int		init_buffer(t_buffer *buf, int capacity);
void		free_buffer(t_buffer *buf);
void		buffer_write(t_buffer *buf, const char *s, int len);
void		buffer_write_char(t_buffer *buf, char c);
void		buffer_output(t_buffer *buf);
int			put_nchar_buf(char c, int n, t_buffer *buf);



#endif
