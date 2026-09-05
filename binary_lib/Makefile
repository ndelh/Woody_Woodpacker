# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 12:57:07 by ndelhota          #+#    #+#              #
#    Updated: 2026/09/04 16:36:46 by ndelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Src = src/
Ut = $(Src)utilities/
Libft = $(Ut)libft/


SRC := $(Src)test.c \
	$(Libft)ft_strlen.c \
	$(Libft)ft_bzero.c \
	$(Libft)ft_memcpy.c \
	$(Libft)ft_memcmp.c

OBJDIR = obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

CC := clang

CFLAGS = -Werror -Wextra -Wall -Iincludes

NAME = binary_lib.a

all : $(OBJ) $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(OBJ) $(BONUSOBJ)
	ar rcs $(NAME) $?

clean :
	rm -rf $(OBJDIR) 

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus


