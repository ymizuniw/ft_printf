# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 15:00:41 by ymizuniw          #+#    #+#              #
#    Updated: 2025/05/13 23:26:38 by ymizuniw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

# ---------- ディレクトリ ----------
SRC_DIRS	= apply apply_utils buffer libft parse_and_dispatch put
OBJ_DIR		= obj

# ---------- ソース収集 ----------
SRC_FILES	= ft_printf.c $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
OBJ_FILES	= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# ---------- ビルドルール ----------
all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $(NAME) $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
