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

# NAME    = libftprintf.a
# CC      = cc
# CFLAGS  = -Wall -Wextra -Werror -g
# AR = ar rcs
# RM = rm -f
# INC = -I.

# MND_DIRS = Mandatory libft .
# BNS_DIRS = apply_format parse_args parse_args_utils parse_format tokenize output libft .

# MND_SRCS	= $(filter-out %/main.c, $(foreach dir, $(MND_DIRS), $(wildcard $(dir)/*.c)))
# BNS_SRCS    = $(filter-out %/main.c, $(foreach dir, $(BNS_DIRS), $(wildcard $(dir)/*.c)))#wildcard should be modified

# MND_OBJ    = $(MND_SRCS:.c=.o)
# BNS_OBJ	= $(BNS_SRCS:.c=.o)

# OBJS = $(MND_OBJ)

# all: $(LIBFT)	$(NAME)

# $(LIBFT):
# 	make bonus -C $(LIBFT_DIR)

# $(NAME): $(OBJS)
# 	@ $(AR)	$(NAME) $(OBJS)

# bonus: OBJS = $(BNS_OBJ)
# bonus: fclean $(LIBFT)
# 	$(AR) $(NAME) $(OBJS)

# clean:
# 	@ $(RM)	$(OBJS)
# 	@make -C $(LIBFT_DIR) clean

# fclean: clean
# 	@ $(RM)	$(NAME)
# 	@make -C $(LIBFT_DIR) fclean

# re: fclean all

# %.o: %.c
# 	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# # test : main.c $(NAME) $(LIBFT)
# # 	$(CC) -fsanitize=address -g -no-pie main.c $(LIBFT) $(NAME) -o ./a.out

# # #other options for test.
# # # PROB = 1
# # # ifeq ($(PROB), 1)
# # # 	CFLAGS += -DMALLOC_TEST
# #endif
# .PHONY: all clean fclean re bonus


NAME     = libftprintf.a
CC       = cc
CFLAGS   = -Wall -Wextra -Werror -g
AR       = ar rcs
RM       = rm -f
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a
INC = -I.

# ディレクトリ定義
# MND_DIRS = libft .
BNS_DIRS = apply_format parse_args parse_args_utils parse_format tokenize output libft .

# ソース抽出（main.c を除外）
MND_SRCS = \
	apply_format_to_args.c \
	ft_utoa.c \
	output_tokens.c \
	ft_itoa_pf.c \
	ft_printf_utils.c \
	ft_xtoa.c \
	set_output_tokens.c \
	ft_printf.c \
	ft_ptoa.c \
	set_out_utils.c

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


# オブジェクトファイル化
MND_OBJ = $(MND_SRCS:.c=.o)
BNS_OBJ = $(BNS_SRCS:.c=.o)

# 通常は Mandatory オブジェクトを使う
OBJS = $(MND_OBJ)

# Mandatory ビルド
all: $(LIBFT) $(NAME)

# Bonus ビルド：Mandatory 無視、BNS_OBJ のみでビルド
bonus: OBJS = $(BNS_OBJ)
bonus: $(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS)

# libft ビルド
$(LIBFT):
	make bonus -C $(LIBFT_DIR)

# 静的ライブラリ作成
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# テスト用：main.c + libftprintf.a + libft.a で a.out を生成
test: main.c $(NAME) $(LIBFT)
	$(CC) -fsanitize=address -g -no-pie main.c $(NAME) $(LIBFT) -o a.out

# クリーン系
clean:
	$(RM) $(MND_OBJ) $(BNS_OBJ)
	@if [ -f $(LIBFT_DIR)/Makefile ]; then make -C $(LIBFT_DIR) clean; fi

fclean: clean
	$(RM) $(NAME) a.out
	@if [ -f $(LIBFT_DIR)/Makefile ]; then make -C $(LIBFT_DIR) fclean; fi

re: fclean all

print-bns:
	@echo "BNS_SRCS = $(BNS_SRCS)"
	@echo "BNS_OBJ  = $(BNS_OBJ)"

# コンパイルルール
%/%.o: %/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY: all bonus test clean fclean re
