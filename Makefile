# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 11:30:22 by aalliot           #+#    #+#              #
#    Updated: 2015/11/25 16:13:56 by aalliot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STATIC_LIB	= libftprintf.a
DEBUG_LIB	= libftprintf_debug.a
DYNAMIC_LIB	= libftprintf.so

SRC		=	ft_printf.c \
			parse.c		\
			parse2.c	\
			print.c		\
			conv_s.c	\
			conv_c.c	\
			conv_d.c	\
			conv_p.c	\
			conv_o.c	\
			conv_x.c	\
			conv_u.c	\
			conv_b.c	\
			hexa.c		\
			utf8.c

DYNAMIC_OBJ	= $(patsubst %.c,$(DYNAMIC_DIR)/%.o,$(SRC))
STATIC_OBJ	= $(patsubst %.c,$(STATIC_DIR)/%.o,$(SRC))
DEBUG_OBJ	= $(patsubst %.c,$(DEBUG_DIR)/%.o,$(SRC))

HEAD_DIR	= includes
SRC_DIR		= src
DEBUG_DIR	= debug
STATIC_DIR	= static
DYNAMIC_DIR	= dynamic

LIBFT_STATIC= libft/libft.a
LIBFT_STATIC_DIR = libft/static/
LIBFT_DEBUG	= libft/libft_debug.a
LIBFT_HEAD	= libft/includes/

CC			= gcc

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	FLAGS	= -Wall -Wextra #-Werror
else
	FLAGS	= -Wall -Wextra -Werror
endif
$(shell mkdir -p $(STATIC_DIR) $(DYNAMIC_DIR) $(DEBUG_DIR))

all: $(STATIC_LIB) # $(DYNAMIC_LIB) $(DEBUG_LIB)

$(STATIC_LIB): $(STATIC_OBJ)
	ar rc $@ libft/static/* $(STATIC_OBJ)
	ranlib $@

# $(DEBUG_LIB): $(DEBUG_OBJ) $(LIBFT_DEBUG)
# 	ar rc $@ $(DEBUG_OBJ)
# 	ranlib $@
#
# $(DYNAMIC_LIB): $(DYNAMIC_OBJ)
# 	$(CC) -O3 -shared -o $@ $(DYNAMIC_OBJ)

$(STATIC_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT_STATIC)
	$(CC) -O3 -I $(HEAD_DIR) -I $(LIBFT_HEAD) -o $@ -c $< $(FLAGS)

# $(DEBUG_DIR)/%.o: $(SRC_DIR)/%.c
# 	$(CC) -I $(HEAD_DIR) -o $@ -c $< $(FLAGS) -g
#
# $(DYNAMIC_DIR)/%.o: $(SRC_DIR)/%.c
# 	$(CC) -O3 -fPIC -I $(HEAD_DIR) -o $@ -c $< $(FLAGS)

$(LIBFT_STATIC):
	make -C libft/ libft.a

$(LIBFT_DEBUG):
	make -C libft/ libft_debug.a

.PHONY: clean fclean re

clean:
	make -C libft/ clean
	@rm -f $(STATIC_OBJ) $(DYNAMIC_OBJ) $(DEBUG_OBJ)

fclean: clean
	make -C libft/ fclean
	@rm -f $(STATIC_LIB) $(DYNAMIC_LIB) $(DEBUG_LIB)

re: fclean all
