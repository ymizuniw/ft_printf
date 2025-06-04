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

NAME    = libftprintf.a

# Directories
SRC_DIRS = apply_format parse_args parse_args_utils parse_format tokenize output libft .

INC      = -I. -Ilibft

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -fsanitize=address


# Find all .c files in directories
SRCS    = $(filter-out %/main.c, $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c)))
OBJS    = $(SRCS:.c=.o)

PROB = 1
ifeq ($(PROB), 1)
	CFLAGS += -DMALLOC_TEST
endif

# Default target
all: $(NAME)

# Archive into static library
$(NAME): $(OBJS)
	@ar rcs $@ $^

# Clean object files
clean:
	@rm -f $(OBJS)

# Clean all
fclean: clean
	@rm -f $(NAME)

# Recompile everything
re: fclean all

# Bonus target if needed
bonus: all

# Compilation rule
%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY: all clean fclean re bonus
