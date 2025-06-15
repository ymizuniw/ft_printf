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

NAME        := libftprintf.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g
AR          := ar
ARFLAGS     := rcs
RM          := rm -f

SRC_DIR     := src
INC_DIR     := include
LIBFT_DIR   := libft
INC         := -I$(INC_DIR) -I$(LIBFT_DIR)

MAND_SRCS := \
    mnd_src/parse_args_utils/ft_ctoa.c \
    mnd_src/parse_args_utils/ft_ptoa.c \
    mnd_src/parse_args_utils/ft_utoa.c \
    mnd_src/parse_args_utils/ft_xtoa.c \
    mnd_src/parse_args_utils/ft_is_upper.c \
    mnd_src/ft_printf.c \
    mnd_src/initialize_and_alloc_tokens.c \
    mnd_src/set_content_len.c \
    mnd_src/set_token_content.c \
    mnd_src/arg_to_ascii.c \
    mnd_src/adjust_index.c \
    mnd_src/output_tokens.c \
    mnd_src/get_token_error_free.c \
    mnd_src/destruct_tokens.c \
    mnd_src/ft_is_spec.c

BONUS_SRCS := \
    bns_src/parse_format/manage_flag_conflict.c \
    bns_src/parse_format/manage_flag_spec.c \
    bns_src/parse_format/parse_flags.c \
    bns_src/parse_format/parse_format.c \
    bns_src/parse_format/parse_format_utils.c \
    bns_src/parse_format/parse_precision.c \
    bns_src/parse_format/parse_specifier.c \
    bns_src/parse_format/parse_width.c \
    bns_src/parse_args_utils/ft_ctoa.c \
    bns_src/parse_args_utils/ft_is_upper.c \
    bns_src/parse_args_utils/ft_itoa_abs.c \
    bns_src/parse_args_utils/ft_ptoa.c \
    bns_src/parse_args_utils/ft_utoa.c \
    bns_src/parse_args_utils/ft_xtoa.c \
    bns_src/parse_args/parse_args.c \
    bns_src/parse_args/arg_to_spec.c \
    bns_src/tokenize/init_free_token.c \
    bns_src/tokenize/tokenize_format.c \
    bns_src/apply_format/apply_format.c \
    bns_src/apply_format/set_count_utils.c \
    bns_src/apply_format/set_output_str.c \
    bns_src/output/output_list.c \
    bns_src/output/output_token.c \
    bns_src/ft_printf_bonus.c

OBJS        := $(MAND_SRCS:.c=.o)
BONUS_OBJS  := $(BONUS_SRCS:.c=.o)

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a temp_libft.a
	@$(AR) x temp_libft.a > /dev/null
	@$(AR) $(ARFLAGS) $@ $^ *.o
	@$(RM) temp_libft.a *.o

bonus: $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) bonus
	@rm -f $(NAME)
	@cp $(LIBFT_DIR)/libft.a temp_libft.a
	@$(AR) x temp_libft.a > /dev/null
	@$(AR) $(ARFLAGS) $(NAME) $^ *.o
	@$(RM) temp_libft.a *.o

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
