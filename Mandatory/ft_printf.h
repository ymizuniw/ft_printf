/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 01:14:44 by ymizuniw          #+#    #+#             */
/*   Updated: 2025/06/05 04:25:03 by ymizuniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
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

typedef enum e_spec
{
	C = 1,
	S,
	D,
	U,
	HEX,
	P
}			t_spec;

// PRINTF
int			ft_printf(const char *format, ...);
int			search_size_token(const char *fmt);
void		free_all_tokens(char **tokens);

// set_output_token
char		**set_output_tokens(va_list ap, const char *fmt,
				int token_array_size);
char		*get_tmp_token(const char *fmt, size_t *i, va_list ap);
void		free_from_error_tokens(size_t t_index, char **token);
char		*ft_strndup(const char *str, size_t n);
int			is_spec(const char c);
int			find_spec(const char c);
t_bool		ft_is_upper(const char c);

char		*apply_format_to_args(va_list ap, const char spec);
char		*ft_ctoa(const char c);
char		*ft_ptoa(void *ptr);
char		*ft_itoa(const int n);
char		*ft_utoa(const unsigned int u);
char		*ft_xtoa(const long n, t_bool is_upper);

int			output_tokens(void);
