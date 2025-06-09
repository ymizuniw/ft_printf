/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 01:14:44 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/09 10:21:08 by ymizuniw         ###   ########.fr       */
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

// main
int			ft_printf(const char *fmt, ...);

// main_scope
int			get_token_array_size(const char *fmt);
int			get_token_content_len(const char *token_start, va_list aq);
void		get_token_error_free(char **tokens, int tk_index);
char		*get_token_content(const char *fmt, int fmt_index,
				int txt_or_arg_len, va_list ap);
int			print_token(char *token_unit);
void		destruct_tokens(char **tokens, int token_array_size);

// parse_args_utils
char		*ft_ctoa(char c);
char		*ft_ptoa(void *ptr);
char		*ft_utoa(unsigned int n);
t_bool		ft_is_upper(char c);

// other_utils
char		*ft_strndup(const char *src, size_t n);
t_bool		ft_is_spec(const char c);
char		*arg_to_ascii(const char spec, va_list aq);
char		*ft_xtoa(unsigned long n, t_bool is_upper);

#endif
