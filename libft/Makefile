# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/27 11:38:00 by ymizuniw          #+#    #+#              #
#    Updated: 2025/06/11 13:01:21 by ymizuniw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g
AR = ar rcs
RM = rm -f

MANDATORY_SRC = $(filter-out %_bonus.c, $(wildcard *.c))
BONUS_SRC = $(wildcard *_bonus.c)

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJS = $(MANDATORY_OBJ)

ifdef BONUS
	OBJS += $(BONUS_OBJ)
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR)	$(NAME)	$(OBJS)

bonus:
	@$(MAKE) BONUS=1 all

clean:
	@$(RM)	$(MANDATORY_OBJ)	$(BONUS_OBJ)

fclean: clean
	@$(RM)	$(NAME)

re: fclean all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
