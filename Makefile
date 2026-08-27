# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 17:08:53 by ndelhota          #+#    #+#              #
#    Updated: 2026/06/01 18:47:36 by ndelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := woody_woodpacker

Ut = ./utilities
Ini = ./init
Mod = ./modify_binary
Gather = ./$(Mod)/gather_intel
64_F = ./64_factory

SRC := main.c \
		$(64_F)/main_header_utils1.c \
		$(64_F)/main_header_utils2.c \
		$(64_F)/declare_64.c \
		$(Ut)/utils.c \
		$(Ut)/print.c \
		$(Ut)/boundary_check.c \
		$(Ut)/debug_print.c \
		$(Ut)/retrieve_longest_padding.c \
		$(Ini)/open_fetch_map.c \
		$(Ini)/check_prerequisite.c \
		$(Mod)/modify_core.c  \
		$(Gather)/retrieve_ehdr_intel.c

CC := cc

CFLAGS := -g -Wall -Werror -Wextra

OBJDIR = obj
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR)/, $(OBJ))


all : $(OBJ) $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $^

clean :
	@rm -rf $(OBJDIR) 

fclean : clean 
	@rm -f $(NAME)

re : fclean all

PHONY : all clean fclean re
