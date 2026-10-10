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
It = iterable/
Init = $(Src)init/
Ut = $(Src)utilities/
Error = $(Ut)error_warning/
Libft = $(Ut)libft/
Print = $(Ut)print/
Dprint = $(Print)debug/
Math = $(Ut)math/
Launcher = $(Ut)launcher/
U_getter = $(Ut)universal_getter/
Shdr = $(Src)shdr/
Phdr= $(Src)phdr/
Opener = $(Src)/opener/
Copy = $(Src)copy/
Copy_Stub = $(Copy)stub_copy/
Parse = $(Src)parse/
Bound_check = $(Parse)boundary_check/
Iter = $(Src)iter/
Gather = $(Src)gather/
Stub = $(Src)stub/
Fs_stub = $(Stub)freestanding_stub/
Fs_cave = $(Fs_stub)caving_stub/
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
	$(Launcher)file_launcher.c \
	$(Error)register_error.c \
	$(Error)warning.c \
	$(Opener)get_file.c \
	$(Opener)get_writable_copy.c \
	$(Opener)opener_utils.c \
	$(Parse)parser.c \
	$(Parse)first_parse.c \
	$(Parse)first_parse_utils.c \
	$(Parse)load_ehdr_content.c \
	$(Parse)parse_ehdr_content.c \
	$(Parse)$(It)phdr_range_check.c \
	$(Parse)$(It)shdr_range_check.c \
	$(Bound_check)oob_check.c \
	$(Bound_check)shstrindex_validity.c \
	$(Bound_check)unvalid_strtab.c \
	$(Iter)iter_phdr.c \
	$(Iter)iter_shdr.c \
	$(Shdr)find_first_of_name.c \
	$(Shdr)get_name.c \
	$(Phdr)phdr_utils.c \
	$(Phdr)stripping_phdr.c \
	$(Stub)stub_utils.c \
	$(S_xor)single_xor_cypher.c \
	$(Fs_stub)freestanding_stubbing.c \
	$(Fs_stub)gather_freestanding_stub_data.c \
	$(Fs_cave)caving_stub.c \
	$(Fs_cave)find_cave.c \
	$(End)free_file.c \
	$(Print)print_ehdr.c \
	$(Ut)gen_random_key.c \
	$(Ut)full_copy_doc.c \
	$(64_F)declare_64.c \
	$(64_Getter)ehdr_getter_64.c \
	$(64_Getter)phdr_getter_64.c \
	$(64_Getter)shdr_getter_64.c \
	$(64_Setter)ehdr_setter_64.c \
	$(64_Setter)phdr_setter_64.c \
	$(64_Setter)shdr_setter_64.c \
	$(Autonomous)barbarious_strip.c \

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


