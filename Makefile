# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymizuniw <ymizuniw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 15:00:41 by ymizuniw          #+#    #+#              #
#    Updated: 2025/05/13 16:56:24 by ymizuniw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

INCLUDES	= -Iincludes
MANDATORY_SRC = ft_printf.c \
				dispatch/dispatch_format.c \
				format/put_char.c \
				format/put_str.c \
				format/put_signed.c \
				format/put_unsigned.c \
				format/put_hex_lower.c \
				format/put_hex_upper.c \
				format/put_ptr.c \
				format/put_percent.c \
