/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 01:14:44 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/11 11:46:47 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.

# ifndef T_BOOL_H
#  define T_BOOL_H
#  define TRUE 1
#  define FALSE 0

typedef int	t_bool;

# endif

typedef struct s_token
{
	char *content;
	char spec;
}	t_token;

typedef struct s_tk_params
{
	int		tk_index;
	int		txt_or_arg_len;
	int		fmt_index;
	int		token_array_size;
	int		token_start_index;
	int		out_len;
	int		count_out_tokens;
}			t_tk_params;

// main
int			ft_printf(const char *fmt, ...);

// main_scope
int			initialize_and_alloc_tokens(const char *fmt, t_token **tokens, t_tk_params *tk_params);
int			set_content_len(const char *fmt, t_tk_params *tk_params,
				va_list aq);
int			set_token_content(const char *fmt, t_token *tokens,
				t_tk_params *tk_params, va_list ap);
char		*arg_to_ascii(const char spec, va_list aq);
void		adjust_index(const char *fmt, t_tk_params *tk_params);
void		get_token_error_free(t_token *tokens, int tk_index);
void		output_tokens(t_token *tokens, t_tk_params *tk_params);
void		destruct_tokens(t_token *tokens, int token_array_size);
t_bool		ft_is_spec(const char c);

// parse_args_utils
char		*ft_ctoa(const char c);
char		*ft_ptoa(void *ptr);
char		*ft_utoa(unsigned int n);
char		*ft_xtoa(unsigned long n, t_bool is_upper);
// t_bool		ft_is_upper(char c);

// other_utils
// char		*ft_strndup(const char *src, size_t n);
char		*arg_to_ascii(const char spec, va_list aq);
t_bool		ft_is_spec(const char c);

#endif
