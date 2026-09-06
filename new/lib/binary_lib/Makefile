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
Init = $(Src)init/
Ut = $(Src)utilities/
Error = $(Ut)error/
Libft = $(Ut)libft/
Print = $(Ut)print/
U_getter = $(Ut)universal_getter/
Shdr_ut = $(Ut)shdr_utils/
Phdr_ut = $(Ut)phdr_utils/
Bound_check = $(Src)boundary_check/
Opener = $(Src)/opener/
Parse = $(Src)parse/
Iterate = $(Ut)iterate/
Gather = $(Src)gather/
End = $(Src)end/
64_F = $(Src)64_factory/
64_Getter = $(64_F)getter/
64_Setter = $(64_F)setter/


SRC := $(Libft)ft_strlen.c \
	$(Libft)ft_bzero.c \
	$(Libft)ft_memcpy.c \
	$(Libft)ft_memcmp.c \
	$(Libft)ft_putendl_fd.c \
	$(Libft)ft_putstr_fd.c \
	$(Libft)ft_putchar_fd.c \
	$(Libft)cr.c \
	$(Libft)positive_pnumber.c \
	$(Print)print_strtab.c \
	$(Print)print_ehdr.c \
	$(Init)init.c \
	$(U_getter)first_ehdr_intel.c \
	$(Opener)open_map.c \
	$(Bound_check)oob_check.c \
	$(Bound_check)unvalid_strtab.c \
	$(Bound_check)shstrindex_validity.c \
	$(Parse)parse_first_header.c \
	$(Parse)parse_content_range.c \
	$(Gather)gather_content.c \
	$(Iterate)iterate_phdr.c \
	$(Iterate)iterate_shdr.c \
	$(Phdr_ut)phdr_range_check.c \
	$(Shdr_ut)shdr_range_check.c \
	$(Shdr_ut)strip_shdr.c \
	$(Error)register_error.c \
	$(64_F)declare_64.c \
	$(64_Getter)ehdr_getter_64.c \
	$(64_Getter)phdr_getter_64.c \
	$(64_Getter)shdr_getter_64.c \
	$(64_Setter)ehdr_setter_64.c \
	$(End)ft_free.c \
	$(End)close_map.c

OBJDIR = obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

CC := clang

CFLAGS = -Werror -Wextra -Wall -g -Iincludes

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


