/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:08:08 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/05/27 21:41:21 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// token type
typedef enum e_token_type
{
	TK_TEXT,
	TK_CONV
}					t_token_type;

// format flag management
typedef struct s_format
{
	int				flag_minus;
	int				flag_zero;
	int				flag_hash;
	int				flag_plus;
	int				flag_space;
	int				width;
	int				precision;
	int				precision_on;
	char			specifier;
}					t_format;

typedef struct s_token
{
	t_token_type	type;
	char			*str;
	t_format		format;
}					t_token;

// specifier group enum for dispatching
typedef enum e_spec_group
{
	GR_NON = 0,
	GR_STRING,
	GR_NUMBER,
	GR_POINTER
}					t_spec_group;

typedef struct s_intfmt_parts {
	int		len_digits;
	int		has_prefix;
	int		prec_zeros;
	int		content_len;
	int		width_padding;
	int		total_len;
}	t_intfmt_parts;

// main
int					ft_printf(const char *format, ...);


// parse 4 functions
t_format			parse_format(const char *s, int *i, va_list args);
void				parse_flags(const char *s, int *i, t_format *f);
void				parse_width(const char *s, int *i, t_format *f,
						va_list args);
void				parse_precision(const char *s, int *i, t_format *f,
						va_list args);
//
int					dispatch_format_token(const char *s, va_list args);

int					put_char_format(char c, t_format f);
int					put_str_format(char *s, t_format f);
int					put_percent_format(t_format f);


int					apply_format_int(int n, t_format f);
int					apply_format_unsigned(unsigned int n, t_format f);
int					apply_format_hex(unsigned int n, t_format f, int is_upper);
int					apply_format_ptr(void *ptr, t_format f);
int					print_prefix(int n, t_format f);

// apply_utils 4 functions
char				*itoa_buf(int n);
char				*utoa_buf(unsigned int n);
char				*utoa_base_buf(unsigned long n, const char *base);
char				*print_padding_int(int len, int has_prefix);

#endif
