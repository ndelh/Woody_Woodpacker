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
Bound_check = $(Src)boundary_check/
Opener = $(Src)/opener/
End = $(Src)end/
64_F = $(Src)64_factory/
64_Getter = $(64_F)getter/
64_Setter = $(64_F)setter/


SRC := $(Src)test.c \
	$(Libft)ft_strlen.c \
	$(Libft)ft_bzero.c \
	$(Libft)ft_memcpy.c \
	$(Libft)ft_memcmp.c \
	$(Libft)ft_putendl_fd.c \
	$(Libft)cr.c \
	$(Opener)compute_filesize.c \
	$(Opener)open_map.c \
	$(Bound_check)oob_check.c \
	$(Bound_check)unvalid_strtab.c \
	$(64_F)declare_64.c \
	$(64_Getter)ehdr_getter_64.c \
	$(64_Getter)phdr_getter_64.c \
	$(64_Getter)shdr_getter_64.c \
	$(64_Setter)ehdr_setter_64.c \
	$(End)ft_end.c

OBJDIR = obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

CC := clang

CFLAGS = -Werror -Wextra -Wall -Iincludes

NAME = binary_lib.a

all : $(NAME)

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


