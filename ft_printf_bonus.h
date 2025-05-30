/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:08:08 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/30 21:19:35 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BOOL_H
#  define BOOL_H
#  define TRUE 1
#  define FALSE 0
typedef int			t_bool;
# endif

// token type separation
typedef enum e_token_type
{
	TXT,
	CONV
}					t_token_type;

// format flag management
typedef struct s_format
{
	t_bool			flag_minus;
	t_bool			flag_zero;
	t_bool			flag_plus;
	t_bool			flag_space;
	t_bool			flag_hash;

	t_bool			width_from_arg;
	int				width;
	t_bool			prec_from_arg;
	int				precision;
	t_bool			precision_on;
	t_bool			is_negative;
	char			spec;
}					t_format;

typedef struct s_token
{
	t_token_type	type;
	char			*block;
	t_format		*format;
	char			*parsed_arg;
}					t_token;

typedef enum e_pad_pos
{
	PAD_NONE,
	PAD_BACK,
	PAD_AFTER_SIGN,
	PAD_FRONT
} t_pad_pos

	typedef struct s_lens
{
	t_pad_pos		pad_pos;
	size_t			prefix;
	size_t			sign;
	size_t			arg;
	size_t			precised;
	size_t			total;
} t_lens

// main
int	ft_printf(const char *format, ...);

// parse
t_format			parse_format(const char *format, int *i, va_list args);
void				parse_flags(const char *fmt, t_format *f, size_t *i);
void				parse_width(const char *format, t_format *f, size_t *i);
void				parse_precision(const char *format, t_format *f, size_t *i);

// put
int					put_char_format(char c, t_format *f);
int					put_str_format(char *format, t_format *f);
int					put_percent_format(t_format *f);

// apply
int					apply_format_int(int n, t_format *f);
int					apply_format_unsigned(unsigned int n, t_format *f);
int					apply_format_hex(unsigned int n, t_format *f, int is_upper);
int					apply_format_ptr(void *ptr, t_format *f);
int					print_prefix(int n, t_format *f);

// apply_utils
int					itoa_buf(char *buf, int n);
int					utoa_buf(char *buf, unsigned int n);
int					utoa_base_buf(char *buf, unsigned long n, const char *base);
int					print_padding_int(t_format f, int len, int has_prefix);

#endif
