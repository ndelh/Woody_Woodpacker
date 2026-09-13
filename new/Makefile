# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 17:08:53 by ndelhota          #+#    #+#              #
#    Updated: 2026/09/13 17:59:36 by ndelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := woody_woodpacker

Ut = ./utilities
Ini = ./init
Mod = ./modify_binary
Gather = ./$(Mod)/gather_intel
64_F = ./64_factory

SRC := main.c \

CC := cc

CFLAGS := -Wall -Werror -Wextra -g -Iincludes #-fsanitize=address

STUB := nasm -f elf64 stub/stub64.s -o stub64.o

OBJDIR = obj
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR)/, $(OBJ))

LIB := ./lib/binary_lib/binary_lib.a

all : $(LIB) $(OBJ) $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@$(STUB)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $^

$(LIB) :
	@make -C lib/binary_lib

clean :
	@rm -rf $(OBJDIR) 
	@make -C lib/binary_lib clean

fclean : clean 
	@rm -f $(NAME)
	@if [ -f Woody ]; then rm Woody; fi
	@if [ -f stub64.o ]; then rm stub64.o; fi

re : fclean
	@make -C lib/binary_lib fclean;
	@make all

PHONY : all clean fclean re
