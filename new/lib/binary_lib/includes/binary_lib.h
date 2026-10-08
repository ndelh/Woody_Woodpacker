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
# include "end.h"
# include "../src/64_factory/elf_64.h"

# define PAGESIZE 4096
# define CANARY_NB 17
# define CANARY_VALUE 0x1122334455667788ULL
# define KEY_PLACE_HOLDER_BEGIN 3
# define PHDR_PLACE_HOLDER_BEGIN 7
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_BOLD    "\033[1m"

//init

t_bin_file	*get_file(char *s);
t_bin_file	*get_copy_file(char *s);

//boundary_check
bool	is_struct_oob(t_bin_file *intel, uint64_t offset, uint64_t struct_nb, uint64_t struct_size);
bool	is_strtab_unvalid(unsigned char *s, size_t len);
void	shstrndx_validity(t_bin_file *file, t_bin_data *data);


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

//error_warning
void	register_error(char *msg, t_bin_file *file);
void	warn(char *s);
void	file_warning(char *s, t_bin_file *file);

//universal getter
bool			is_not_elf(const void *map);
bool			is_version_unvalid(const void *map);
bool			is_b_endian(const void *map);
uint64_t		get_byte_type(const void *map);

//print 
void	print_strtab(unsigned char *s, uint64_t size);
void	print_ehdr(t_bin_file *file);
void	print_both_ehdr(t_bin_data *data);
	//debug_print
	void	print_all_phdr_range(t_bin_file *file, t_bin_data *data);

# define ft_perror(s) ft_putendl_fd(s, 2)
# define CR_DEFAULT cr(STDIN_FILENO)

//cypher 
void	cypher_pt_load(t_bin_data *data);
void	s_xor_cypher_s(void *to_cypher, size_t cypher_len, void *key_sum);

//math
int		is_power_2(uint64_t x);
bool	is_inf(uint64_t a, uint64_t b);
uint64_t	find_next_aligned_value(uint64_t value, uint64_t align);

//copy
void		simple_cpy(t_bin_data *data, char *s);
void		stripped_copy(t_bin_data *data, char *s);
	//stub_copy
		//free_standing stub copy
		void	fs_basic_stub_copy(t_bin_data *data, char *new_doc);
		bool	fs_caving_stub(t_bin_data *data, char *new_doc);

//parser
void		parse_first_header(t_bin_data *data, t_bin_file *file);
void		parse_ehdr_content_range(t_bin_data *data);
void		first_parse(t_bin_data *data);


//gather
void		gather_ehdr_content(t_bin_data *data);

//iterate
void	iterate_shdr(t_bin_file *file, t_bin_data *data, void *aux_data, void(*func)(t_bin_file *file, t_bin_data *data, void *, void*));
void	iterate_phdr(t_bin_file *file, t_bin_data *data, void *aux_data, void(*func)(t_bin_file *file, t_bin_data *data, void *, void*));

//phdr_utils
void	phdr_range_check(t_bin_file *file, t_bin_data *data, void *aux_data, void *cursor);
//find
	uint64_t	retrieve_farthest_physical(t_bin_file *file, t_bin_data *data);
	uint64_t    get_next_available_vaddr(t_bin_file *file, t_bin_data *data);
	void		*find_first_phdr_of_type(t_bin_file *file, t_bin_data *data, uint64_t type);
	void		*find_cave(t_bin_file *file, t_bin_data *data);
	uint64_t	find_bss_size(const t_elf_ops *elf_caster, void *cursor);


//shdr_utils
	//parse
		void	shdr_range_check(t_bin_file *file, t_bin_data *data, void *aux_data, void *cursor);
	//strip
		void	strip_shdr(t_bin_file *file, t_bin_data *data);
		void	destroy_current_shdr(t_bin_file *file, t_bin_data *data, void *aux_data, void *cursor);
	//find
		char	*get_name(void *cursor, t_bin_file *file);
		void    *find_shdr_by_name(t_bin_file *file, t_bin_data *data, char *name);


//stub
void    craft_stub_phdr(t_bin_data *data, void *phdr);

	//freestanding stub
	void	gather_fs_stub_data(t_bin_data *data);
	void	fs_find_canaries(t_bin_data *data, void *cursor, uint64_t size, t_stub_injector *injector);
	void	compute_ep_offset(t_bin_file *file, t_bin_data *data, uint64_t oep, uint64_t new_ep);

//full fonctions, can be launched as autonomous prog or wrapper
//autonomous
int		autonomous_get_Elf_Class(char *s);
//wrapper
void	resize_after_strip(t_bin_file *file, t_bin_data *data, int fd);


# define DEFAULT_ERROR(x) ft_end(x, 1)

# endif
