# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 17:08:53 by ndelhota          #+#    #+#              #
#    Updated: 2026/09/06 21:49:13 by ndelhota         ###   ########.fr        #
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

CFLAGS := -Wall -Werror -Wextra -g -Iincludes

OBJDIR = obj
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR)/, $(OBJ))

LIB := ./lib/binary_lib/binary_lib.a

all : $(LIB) $(OBJ) $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

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

re : fclean
	@make -C lib/binary_lib fclean;
	@make all

PHONY : all clean fclean re
