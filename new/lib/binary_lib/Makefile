# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 12:57:07 by ndelhota          #+#    #+#              #
#    Updated: 2026/10/08 15:03:55 by ndelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Src = src/
Init = $(Src)init/
Ut = $(Src)utilities/
Error = $(Ut)error_warning/
Libft = $(Ut)libft/
Print = $(Ut)print/
Dprint = $(Print)debug/
Math = $(Ut)math/
U_getter = $(Ut)universal_getter/
Shdr_ut = $(Ut)shdr_utils/
Phdr_ut = $(Ut)phdr_utils/
Bound_check = $(Src)boundary_check/
Opener = $(Src)/opener/
Copy = $(Src)copy/
Copy_Stub = $(Copy)stub_copy/
Parse = $(Src)parse/
Iterate = $(Ut)iterate/
Gather = $(Src)gather/
Stub = $(Src)stub/
Fs_stub = $(Stub)freestanding_stub/
End = $(Src)end/
Cypher = $(Src)cypher/
S_xor = $(Cypher)single_xor/
64_F = $(Src)64_factory/
64_Getter = $(64_F)getter/
64_Setter = $(64_F)setter/
Autonomous = $(Src)autonomous_one/


C_SRC := $(Libft)ft_strlen.c \
	$(Libft)ft_bzero.c \
	$(Libft)ft_memcpy.c \
	$(Libft)ft_memcmp.c \
	$(Libft)ft_putendl_fd.c \
	$(Libft)ft_putstr_fd.c \
	$(Libft)ft_putchar_fd.c \
	$(Libft)cr.c \
	$(Libft)ft_strcmp.c \
	$(Libft)malloc_wrapper.c \
	$(Libft)positive_pnumber.c \
	$(Libft)malloc_wrapper.c \
	$(Print)print_strtab.c \
	$(Print)print_ehdr.c \
	$(Dprint)phdr_all_range.c \
	$(Math)is_power_2.c \
	$(Math)find_next_align_value.c \
	$(Math)is_inf.c \
	$(Error)register_error.c \
	$(Opener)get_file.c \
	$(Opener)get_writable_copy.c \
	$(Opener)opener_utils.c \
	$(End)free_file.c \

ASM_SRC := $(S_xor)s_xor_cypher_s.s

OBJDIR = obj

C_OBJ := $(C_SRC:%.c=$(OBJDIR)/%.o)
ASM_OBJ := $(ASM_SRC:%.s=$(OBJDIR)/%.o)
OBJ = $(C_OBJ) $(ASM_OBJ)

CC := clang
CFLAGS := -Werror -Wextra -Wall -g -Iincludes

ASM_CC := nasm
ASM_FLAGS := -f elf64  

NAME = binary_lib.a

all : $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: %.s
	mkdir -p $(dir $@)
	$(ASM_CC) $(ASM_FLAGS) $< -o $@

bonus : $(OBJ) $(BONUSOBJ)
	ar rcs $(NAME) $?

clean :
	rm -rf $(OBJDIR) 

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus


