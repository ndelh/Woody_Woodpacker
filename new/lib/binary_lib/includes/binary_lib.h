/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 15:37:26 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/08 15:04:50 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_LIB_H
# define BINARY_LIB_H

# include <sys/syscall.h>
# include <sys/mman.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <elf.h>
# include <stdbool.h>

# include "struct.h"
# include "opener.h"
# include "parser.h"
# include "end.h"
# include "utilities.h"
# include "stub.h"
# include "shdr.h"
# include "phdr.h"
# include "iter.h"
# include "report.h"
# include "../src/64_factory/elf_64.h"
# include "../src/32_factory/elf_32.h"

# define PAGESIZE 4096
# define CANARY_NB 17
# define CANARY_VALUE_64 0x1122334455667788ULL
# define CANARY_VALUE_32 UINT32_C(0x11223344)
# define KEY_PLACE_HOLDER_BEGIN 3
# define PHDR_PLACE_HOLDER_BEGIN 7
# define STUB64 "stub64.o"
# define STUB32 "stub32.o"
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_BOLD    "\033[1m"
#define COLOR_PURPLE  "\033[38;5;129m"

//init


//launcher

void	file_launcher(t_bin_file *file, void(*func)(t_bin_file *));


//libft

int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s1, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	cr(int fd);
void	*malloc_wrapper(uint64_t nb, uint64_t size, char *msg);
void    positive_pnumber(unsigned int i, int fd);

//universal getter
bool			is_not_elf(const void *map);
bool			is_version_unvalid(const void *map);
bool			is_b_endian(const void *map);
uint64_t		get_byte_type(const void *map);

//print 
void	print_strtab(unsigned char *s, uint64_t size);
void	print_ehdr(t_bin_file *file);
	//debug_print
	void	print_all_phdr_range(t_bin_file *file);

# define ft_perror(s) ft_putendl_fd(s, 2)
# define CR_DEFAULT cr(STDIN_FILENO)

//cypher 
void	cypher_pt_load(t_bin_file *target, t_bin_file *stub);
void	s_xor_cypher_s(void *to_cypher, size_t cypher_len, void *key_sum);

//math
int		is_power_2(uint64_t x);
bool	is_inf(uint64_t a, uint64_t b);
uint64_t	find_next_aligned_value(uint64_t value, uint64_t align);


//full fonctions, can be launched as autonomous prog or wrapper
//autonomous
int		autonomous_get_Elf_Class(char *s);
//wrapper
void	barbarious_strip(char *s);


# endif
