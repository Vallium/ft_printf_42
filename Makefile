# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 11:30:22 by aalliot           #+#    #+#              #
#    Updated: 2015/01/02 16:57:31 by aalliot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STATIC_LIB	= libftprintf.a
DEBUG_LIB	= libftprintf_debug.a
DYNAMIC_LIB	= libftprintf.so

SRC		=	ft_printf.c

DYNAMIC_OBJ	= $(patsubst %.c,$(DYNAMIC_DIR)/%.o,$(SRC))
STATIC_OBJ	= $(patsubst %.c,$(STATIC_DIR)/%.o,$(SRC))
DEBUG_OBJ	= $(patsubst %.c,$(DEBUG_DIR)/%.o,$(SRC))

HEAD_DIR	= includes
SRC_DIR		= src
DEBUG_DIR	= debug
STATIC_DIR	= static
DYNAMIC_DIR	= dynamic

CC			= gcc
NORMINETTE	= ~/project/colorminette/colorminette

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	FLAGS	= -Wall -Wextra #-Werror
else
	FLAGS	= -Wall -Wextra -Werror
endif
$(shell mkdir -p $(STATIC_DIR) $(DYNAMIC_DIR) $(DEBUG_DIR))

all: $(STATIC_LIB) $(DYNAMIC_LIB) $(DEBUG_LIB)

$(STATIC_LIB): $(STATIC_OBJ)
	ar rc $@ $(STATIC_OBJ)
	ranlib $@

$(DEBUG_LIB): $(DEBUG_OBJ)
	ar rc $@ $(DEBUG_OBJ)
	ranlib $@

$(DYNAMIC_LIB): $(DYNAMIC_OBJ)
	$(CC) -O3 -shared -o $@ $(DYNAMIC_OBJ)

$(STATIC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -O3 -I $(HEAD_DIR) -o $@ -c $< $(FLAGS)

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -I $(HEAD_DIR) -o $@ -c $< $(FLAGS) -g

$(DYNAMIC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -O3 -fPIC -I $(HEAD_DIR) -o $@ -c $< $(FLAGS)

.PHONY: clean fclean re norme

norme:
	@$(NORMINETTE) $(SRC_DIR)/ $(HEAD_DIR)/

clean:
	@rm -f $(STATIC_OBJ) $(DYNAMIC_OBJ) $(DEBUG_OBJ)

fclean: clean
	@rm -f $(STATIC_LIB) $(DYNAMIC_LIB) $(DEBUG_LIB)

re: fclean all
