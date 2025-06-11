/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:08:08 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/11 14:52:50 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft.h"
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

typedef struct s_parts_out
{
	char			prefix[3];
	char			sign[2];
	char			*precised_arg;
	char			*padding;
	size_t			prefix_len;
	size_t			sign_len;
	size_t			prec_len;
	size_t			pad_len;
}					t_parts_out;

typedef enum e_pad_pos
{
	NONE,
	BACK,
	MIDDLE,
	FRONT
}					t_pad_pos;

typedef struct s_lens
{
	t_pad_pos		pad_pos;
	size_t			prefix;
	size_t			sign;
	size_t			arg;
	size_t			prec;
	size_t			pad;
	size_t			total;
}					t_lens;

typedef struct s_token
{
	t_token_type	type;
	char			*block;
	t_format		*format;
	char			*parsed_arg;
	t_lens			*lens;
}					t_token;

// main
int					ft_printf(const char *format, ...);

// tokenize_format
t_list				*tokenize_format(const char *fmt);

// parse_format
void				parse_format(const char *fmt, t_format *f, size_t *place);
void				parse_flags(const char *fmt, t_format *f, size_t *place);
void				parse_width(const char *fmt, t_format *f, size_t *place);
void				parse_precision(const char *fmt, t_format *f,
						size_t *place);
t_bool				parse_specifier(const char *fmt, t_format *f,
						size_t *place);
void				manage_flag_conflict(t_format *f);
void				manage_flag_spec(t_format *f);

// parse_format_utils
int					is_flag(const char c);
int					is_specifier(const char c);
t_token				*initialize_token(void);
void				initialize_format(t_format *f);
void				free_token(void *ptr);
// parse_args
t_bool				parse_args(t_list *tokens, va_list ap);

// parse_args_utils
char				*ft_ctoa(char c);
t_bool				ft_is_upper(char c);
char				*ft_itoa_abs(int n);
char				*ft_ptoa(void *ptr);
char				*ft_utoa(unsigned int n);
char				*ft_xtoa(unsigned long num, t_bool is_upper);

// apply_format
char				*apply_format(t_token *token, t_format *f);

// apply_format_utils
t_bool				is_num_spec(char spec);
size_t				set_count_sign(t_format *f, char *sign);
size_t				set_count_precision(t_format *f, size_t arg_len);
size_t				set_count_prefix(t_format *f, char *prefix,
						char *parsed_arg);
size_t				set_count_pad(t_format *f, t_lens *lens);
void				set_output_str(char *output_str, t_parts_out *parts,
						t_lens *lens);

// output
int					output_token(const char *ouput_str, size_t len, int spec);
int					output_list(t_list *node);

#endif
