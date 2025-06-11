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

# ─── コンパイル/リンク設定 ─────────────────────
NAME        := libftprintf.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g
AR          := ar
ARFLAGS     := rcs
RM          := rm -f

# ─── ディレクトリ定義 ─────────────────────
SRC_DIR     := src
INC_DIR     := include
LIBFT_DIR   := libft
INC         := -I$(INC_DIR) -I$(LIBFT_DIR)

# ─── Mandatoryソース一覧（明示） ─────────────
MAND_SRCS := \
	parse_args_utils_mnd/ft_ctoa.c \
	parse_args_utils_mnd/ft_ptoa.c \
	parse_args_utils_mnd/ft_utoa.c \
	parse_args_utils_mnd/ft_xtoa.c \
	parse_args_utils_mnd/ft_is_upper.c \
	src/ft_printf.c \
	src/initialize_and_alloc_tokens.c \
	src/set_content_len.c \
	src/set_token_content.c \
	src/arg_to_ascii.c \
	src/adjust_index.c \
	src/output_tokens.c \
	src/get_token_error_free.c \
	src/destruct_tokens.c \
	src/ft_is_spec.c

# ─── Bonusソース一覧（明示） ───────────────
BONUS_SRCS := \
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

# ─── Objectファイル一覧 ───────────────────────
OBJS        := $(MAND_SRCS:.c=.o)
BONUS_OBJS  := $(BONUS_SRCS:.c=.o)

# ─── ルール定義 ──────────────────────────────
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
