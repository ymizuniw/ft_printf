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

NAME		= libftprintf.a

SRC_DIRS	= apply apply_utils buffer parse_and_dispatch put .
OBJ_DIR		= obj

SRC			= $(shell find $(SRC_DIRS) -name '*.c')
OBJ			= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f
MKDIR		= mkdir -p

all: $(NAME)

bonus: all

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# 元のファイル階層を obj に写してコンパイル
$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
