# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 15:00:41 by ymizuniw          #+#    #+#              #
#    Updated: 2025/05/13 20:50:30 by ymizuniw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME	= libftprintf.a
# CC		= cc
# CFLAGS	= -Wall -Wextra -Werror
# AR		= ar rcs
# RM		= rm -f

# INCLUDES	= -Iincludes
# MANDATORY_SRC = ft_printf.c \
# 				dispatch/dispatch_format.c \
# 				format/put_char.c \
# 				format/put_str.c \
# 				format/put_signed.c \
# 				format/put_unsigned.c \
# 				format/put_hex_lower.c \
# 				format/put_hex_upper.c \
# 				format/put_ptr.c \
# 				format/put_percent.c \

# **************************************************************************** #
#                               ft_printf - Makefile                          #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

# ---------- ソース定義 ----------

MANDATORY_SRC = \
	ft_printf.c \
	parse/dispatch_format.c \
	buffer/buffer_init.c \
	buffer/buffer_write.c \
	buffer/buffer_flush.c \
	buffer/put_nchar_buf.c \
	format/apply_format_int.c \
	format/apply_format_unsigned.c \
	format/apply_format_hex.c \
	format/apply_format_ptr.c \
	format/put_char_format.c \
	format/put_str_format.c \
	format/put_percent_format.c \
	format/itoa_buf.c \
	format/utoa_buf.c \
	format/utoa_base_buf.c

BONUS_SRC = \
	ft_printf.c \
	parse/dispatch_format_bonus.c \
	parse/parse_format_bonus.c \
	buffer/buffer_init.c \
	buffer/buffer_write.c \
	buffer/buffer_flush.c \
	buffer/put_nchar_buf.c \
	format/apply_format_int.c \
	format/apply_format_unsigned.c \
	format/apply_format_hex.c \
	format/apply_format_ptr.c \
	format/put_char_format_bonus.c \
	format/put_str_format.c \
	format/put_percent_format.c \
	format/prefix.c \
	format/padding_int.c \
	format/itoa_buf.c \
	format/utoa_buf.c \
	format/utoa_base_buf.c

# ---------- オブジェクト変換 ----------

OBJ_DIR			= obj
OBJ_MANDATORY	= $(addprefix $(OBJ_DIR)/, $(MANDATORY_SRC:.c=.o))
OBJ_BONUS		= $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

# ---------- ビルドルール ----------

all: $(NAME)

$(NAME): $(OBJ_MANDATORY)
	$(AR) $(NAME) $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJ_MANDATORY) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
