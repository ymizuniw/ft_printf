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

# NAME     = libftprintf.a
# CC       = cc -$(LIBFT)
# CFLAGS   = -Wall -Wextra -Werror
# AR       = ar rcs
# RM       = rm -f
# INC = -Ilibft -Iinclude

# LIBFT_DIR = libft
# LIBFT     = $(LIBFT_DIR)/libft.a

# MND_SRCS = \
# 	src/apply_format_to_args.c \
# 	src/ft_utoa.c \
# 	src/output_tokens.c \
# 	src/ft_itoa_pf.c \
# 	src/ft_printf_utils.c \
# 	src/ft_xtoa.c \
# 	src/set_output_tokens.c \
# 	src/ft_printf.c \
# 	src/ft_ptoa.c \
# 	src/set_out_utils.c

# # BNS_DIRS = apply_format parse_args parse_args_utils parse_format tokenize output libft .
# BNS_SRCS = \
# 	parse_format/manage_flag_conflict.c \
# 	parse_format/manage_flag_spec.c \
# 	parse_format/parse_flags.c \
# 	parse_format/parse_format.c \
# 	parse_format/parse_format_utils.c \
# 	parse_format/parse_precision.c \
# 	parse_format/parse_specifier.c \
# 	parse_format/parse_width.c \
# 	parse_args_utils/ft_ctoa.c \
# 	parse_args_utils/ft_is_upper.c \
# 	parse_args_utils/ft_itoa_abs.c \
# 	parse_args_utils/ft_ptoa.c \
# 	parse_args_utils/ft_utoa.c \
# 	parse_args_utils/ft_xtoa.c \
# 	parse_args/parse_args.c \
# 	tokenize/init_free_token.c \
# 	tokenize/tokenize_format.c \
# 	apply_format/apply_format.c \
# 	apply_format/set_count_utils.c \
# 	apply_format/set_output_str.c \
# 	output/output_list.c \
# 	output/output_token.c \
# 	ft_printf_bonus.c

# BNS_OBJ = $(BNS_SRCS:.c=.o)
# MND_OBJ = $(MND_SRCS:.c=.o)

# all: $(LIBFT) $(NAME)

# $(LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR) bonus

# $(NAME): $(MND_OBJ) $(LIBFT)
# 		$(AR) $@ $^

# bonus: clean_mnd_objs $(MND_OBJ)
# 	$(AR) $(NAME) $(LIBFT) $(BNS_OBJ)
# # bonus: $(BNS_OBJ) $(LIBFT)
# # 		$(AR) $(NAME) $(OBJS)

# clean:
# 	make clean -C $(LIBFT_DIR)
# 	$(RM) $(MND_OBJ) $(BNS_OBJ)

# clean_mnd_objs:
# 		$(RM) $(MND_OBJ)

# fclean: clean
# 	make fclean -C $(LIBFT_DIR)
# 	$(RM) $(NAME)

# re: fclean all

# %.%o: %.%c
# 	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# test: main.c $(NAME) $(LIBFT)
# 	$(CC)  -g -no-pie $(INC) main.c $(NAME) $(LIBFT) -o a.out
# # -fsanitize=address
# # cc main.c libftprintf.a libft/libft.a -Ilibft -Iinclude -o a.out

# .PHONY: all bonus test clean fclean re


# NAME := libftprintf.a
# CC := cc
# CFLAGS := -Wall -Wextra -Werror
# AR := ar rcs
# RM := rm -f
# INC := -Ilibft -Iinclude #header scope

# #src dir, src files.
# MND_DIRS := src
# MND_SRCS := \
# 	src/apply_format_to_args.c \
# 	src/ft_utoa.c \
# 	src/output_tokens.c \
# 	src/ft_itoa_pf.c \
# 	src/ft_printf_utils.c \
# 	src/ft_xtoa.c \
# 	src/set_output_tokens.c \
# 	src/ft_printf.c \
# 	src/ft_ptoa.c \
# 	src/set_out_utils.c

# BNS_DIRS := apply_format parse_args parse_args_utils parse_format tokenize output .
# BNS_SRCS := \
# 	parse_format/manage_flag_conflict.c \
# 	parse_format/manage_flag_spec.c \
# 	parse_format/parse_flags.c \
# 	parse_format/parse_format.c \
# 	parse_format/parse_format_utils.c \
# 	parse_format/parse_precision.c \
# 	parse_format/parse_specifier.c \
# 	parse_format/parse_width.c \
# 	parse_args_utils/ft_ctoa.c \
# 	parse_args_utils/ft_is_upper.c \
# 	parse_args_utils/ft_itoa_abs.c \
# 	parse_args_utils/ft_ptoa.c \
# 	parse_args_utils/ft_utoa.c \
# 	parse_args_utils/ft_xtoa.c \
# 	parse_args/parse_args.c \
# 	tokenize/init_free_token.c \
# 	tokenize/tokenize_format.c \
# 	apply_format/apply_format.c \
# 	apply_format/set_count_utils.c \
# 	apply_format/set_output_str.c \
# 	output/output_list.c \
# 	output/output_token.c \
# 	ft_printf_bonus.c

# #obj define
# MND_OBJ := $(MND_SRC:.c=.o)
# BNS_OBJ := $(BNS_SRC:.c=.o)

# OBJ := $(MND_OBJ)
# ifdef BONUS
# 	OBJ := $(BNS_OBJ)
# endif

# LIBFT_DIR := libft
# LIBFT := $(LIBFT_DIR)/libft.a
# $(LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR) bonus

# all: $(LIBFT) $(NAME)

# $(NAME): $(OBJS)
# 	@$(RM)
# 	$(AR) $@ $(OBJ)
# 	@$(AR) x $(LIBFT)
# 	@$(AR) rcs $@ *.o
# 	@$(RM) *.o
# 	@echo "$(NAME) built ($(if $(BONUS), bonus, mandatory))"

# bonus:
# 	@$(MAKE) BONUS=1 all

# %.o: %.%c
# 	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# clean:
# 	@$(RM)	$(MND_OBJ)	$(BNS_OBJ)

# fclean: clean
# 	@$(RM)	$(NAME)

# re: fclean all

# .PHONY: all bonus clean fclean re

# NAME      := libftprintf.a
# CC        := cc
# CFLAGS    := -Wall -Wextra -Werror
# AR        := ar
# ARFLAGS   := rcs
# RM        := rm -f
# INC       := -Iinclude -Ilibft       # ヘッダ探索パス

# # ─── ソース一覧 ────────────────────────────────
# MND_SRCS  := \
#  src/apply_format_to_args.c \
#  src/ft_utoa.c \
#  src/output_tokens.c \
#  src/ft_itoa_pf.c \
#  src/ft_printf_utils.c \
#  src/ft_xtoa.c \
#  src/set_output_tokens.c \
#  src/ft_printf.c \
#  src/ft_ptoa.c \
#  src/set_out_utils.c

# BNS_SRCS  := \
#  parse_format/manage_flag_conflict.c \
#  parse_format/manage_flag_spec.c \
#  parse_format/parse_flags.c \
#  parse_format/parse_format.c \
#  parse_format/parse_format_utils.c \
#  parse_format/parse_precision.c \
#  parse_format/parse_specifier.c \
#  parse_format/parse_width.c \
#  parse_args_utils/ft_ctoa.c \
#  parse_args_utils/ft_is_upper.c \
#  parse_args_utils/ft_itoa_abs.c \
#  parse_args_utils/ft_ptoa.c \
#  parse_args_utils/ft_utoa.c \
#  parse_args_utils/ft_xtoa.c \
#  parse_args/parse_args.c \
#  tokenize/init_free_token.c \
#  tokenize/tokenize_format.c \
#  apply_format/apply_format.c \
#  apply_format/set_count_utils.c \
#  apply_format/set_output_str.c \
#  output/output_list.c \
#  output/output_token.c \
#  ft_printf_bonus.c

# MND_OBJ := $(MND_SRCS:.c=.o)
# BNS_OBJ := $(BNS_SRCS:.c=.o)

# OBJ     := $(MND_OBJ)                # mandatory がデフォルト
# ifdef BONUS
#   OBJ   := $(MND_OBJ) $(BNS_OBJ)     # bonus は上乗せ
# endif

# # ─── libft ─────────────────────────────────────
# LIBFT_DIR := libft
# LIBFT_A   := $(LIBFT_DIR)/libft.a
# $(LIBFT_A):
# 	$(MAKE) -C $(LIBFT_DIR) bonus     # 初回のみ生成

# # ─── 目標 ─────────────────────────────────────
# all: $(LIBFT_A) $(NAME)

# $(NAME): $(OBJ)
# 	@$(RM) $@                       # 旧版削除
# 	$(AR) $(ARFLAGS) $@ $(OBJ)      # ① printf 側 .o
# 	@$(AR) x $(LIBFT_A)             # ② libft 展開
# 	@$(AR) $(ARFLAGS) $@ *.o        # ③ 取り込み
# 	@$(RM) *.o

# bonus:
# 	@$(MAKE) BONUS=1 all             # OBJ が自動的に bonus 構成へ

# # ─── 汎用規則 ＆ 掃除 ───────────────────────────
# %.o: %.%c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# clean: ; $(RM) $(MND_OBJ) $(BNS_OBJ)
# 		$(MAKE) -C $(LIBFT_DIR) clean

# fclean: clean
# 		$(RM) $(NAME) a.out
# 		$(MAKE) -C $(LIBFT_DIR) fclean

# re: fclean all
# .PHONY: all bonus clean fclean re





# # ─── 基本設定 ────────────────────────────────
# NAME     := libftprintf.a
# CC       := cc
# CFLAGS   := -Wall -Wextra -Werror -Ilibft -Iinclude
# AR       := ar
# ARFLAGS  := rcs
# RM       := rm -f

# SRC_DIR  := src
# INC_DIR  := include
# LIBFT_DIR:= libft

# SRCS     := $(wildcard $(SRC_DIR)/*.c)
# OBJS     := $(SRCS:.c=.o)

# INC      := -I$(INC_DIR) -I$(LIBFT_DIR)

# .PHONY: all clean fclean re

# all: $(NAME)

# $(NAME): $(OBJS)
# 	@$(MAKE) -C $(LIBFT_DIR)
# 	@cp $(LIBFT_DIR)/libft.a temp_libft.a
# 	@$(AR) x temp_libft.a                   # 展開して .o を取得
# 	@$(AR) $(ARFLAGS) $@ $^ *.o             # printf .o と libft .o を統合
# 	@$(RM) temp_libft.a *.o

# %.o: %.c
# 	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# clean:
# 	$(RM) $(OBJS)
# 	$(MAKE) -C $(LIBFT_DIR) clean

# fclean: clean
# 	$(RM) $(NAME)
# 	$(MAKE) -C $(LIBFT_DIR) fclean

# re: fclean all
# ─── 基本設定 ────────────────────────────────



NAME      := libftprintf.a
CC        := cc
CFLAGS    := -Wall -Wextra -Werror
AR        := ar
ARFLAGS   := rcs
RM        := rm -f

SRC_DIR   := src
INC_DIR   := include
LIBFT_DIR := libft

MAND_SRCS := parse_args_utils_mnd/ft_ctoa.c \
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

BONUS_DIRS = apply_format parse_args parse_args_utils parse_format tokenize output libft .
BONUS_SRCS = \
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


OBJS      := $(MAND_SRCS:.c=.o)
BONUS_OBJS:= $(BONUS_SRCS:.c=.o)

INC       := -I$(INC_DIR) -I$(LIBFT_DIR)

# ─── ターゲット定義 ─────────────────────────────
.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a temp_libft.a
	@$(AR) x temp_libft.a
	@$(AR) $(ARFLAGS) $@ $^ *.o
	@$(RM) temp_libft.a *.o

bonus: $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) bonus
	@cp $(LIBFT_DIR)/libft.a temp_libft.a
	@$(AR) x temp_libft.a
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
