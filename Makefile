# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 15:00:41 by ymizuniw          #+#    #+#              #
#    Updated: 2025/05/13 16:43:41 by ymizuniw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

INCLUDES	= -Iincludes
SRC = \
		ft_printf.c \
		apply/apply_format_int.c \
		apply/apply_format_hex.c \
		format/put_char_format.c \
		format/put_str_format.c \
		buffer/buffer.c \
		buffer/put_nchar_buf.c \
		dispatch/dispatch_format.c
