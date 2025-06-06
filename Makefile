# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yourlogin <yourlogin@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: YYYY/MM/DD                              #+#    #+#              #
#    Updated: YYYY/MM/DD                              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = libftprintf.a
CC       = cc
CFLAGS   = -Wall -Wextra -Werror
AR       = ar rcs
RM       = rm -f
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a
INC = -I$(LIBFT_DIR) -Iinclude

MND_SRCS = \
	src/apply_format_to_args.c \
	src/ft_utoa.c \
	src/output_tokens.c \
	src/ft_itoa_pf.c \
	src/ft_printf_utils.c \
	src/ft_xtoa.c \
	src/set_output_tokens.c \
	src/ft_printf.c \
	src/ft_ptoa.c \
	src/set_out_utils.c

# BNS_DIRS = apply_format parse_args parse_args_utils parse_format tokenize output libft .
BNS_SRCS = \
	parse_format/manage_flag_conflict.c \
	parse_format/manage_flag_spec.c \
	parse_format/parse_flags.c \
	parse_format/parse_format.c \
	parse_format/parse_format_utils.c \
	parse_format/parse_precision.c \
	parse_format/parse_specifier.c \
	parse_format/parse_width.c \
	parse_args_utils/ft_ctoa.c \
	parse_args_utils/ft_is_upper.c \
	parse_args_utils/ft_itoa_abs.c \
	parse_args_utils/ft_ptoa.c \
	parse_args_utils/ft_utoa.c \
	parse_args_utils/ft_xtoa.c \
	parse_args/parse_args.c \
	tokenize/init_free_token.c \
	tokenize/tokenize_format.c \
	apply_format/apply_format.c \
	apply_format/set_count_utils.c \
	apply_format/set_output_str.c \
	output/output_list.c \
	output/output_token.c \
	ft_printf_bonus.c

BNS_OBJ = $(BNS_SRCS:.c=.o)
MND_OBJ = $(MND_SRCS:.c=.o)

OBJS = $(MND_OBJ)

all: $(LIBFT) $(NAME)

bonus: OBJS = $(BNS_OBJ)
bonus: $(BNS_OBJ) $(LIBFT)
		$(AR) $(NAME) $(OBJS)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(MND_OBJ) $(BNS_OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) a.out

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
%.%o: %.%c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

test: main.c $(NAME) $(LIBFT)
	$(CC) -fsanitize=address -g -no-pie $(INC) main.c $(NAME) $(LIBFT) -o a.out

# cc main.c libftprintf.a libft/libft.a -Ilibft -Iinclude -o a.out

.PHONY: all bonus test clean fclean re
