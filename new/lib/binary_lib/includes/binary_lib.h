/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 15:37:26 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/04 15:59:29 by ndelhota         ###   ########.fr       */
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

# include "../src/64_factory/elf_64.h"

# define PAGESIZE 4096
# define CANARY_NB 5
# define CANARY_VALUE 0x1122334455667788ULL

typedef struct s_elf_ops
{
	// basic getter
		uint64_t	(*get_entry)(const void *ogn_map);
		uint64_t	(*get_phdr_offset)(const void *ogn_map);
		uint64_t	(*get_phdr_nb)(const void *ogn_map);
		uint64_t	(*get_phdr_size)(const void *ogn_map);
		uint64_t	(*get_shdr_offset)(const void *ogn_map);
		uint64_t	(*get_shdr_nb)(const void *ogn_map);
		uint64_t	(*get_shdr_size)(const void *ogn_map);
		uint64_t	(*get_shstrndx)(const void *ogn_map);
	//will do some sort, for the moment we just fetch all data in phdr
		uint64_t	(*get_ptype)(const void *cursor);
		uint64_t	(*get_poffsset)(const void *cursor);
		uint64_t	(*get_pvaddr)(const void *cursor);
		uint64_t	(*get_paddr)(const void *cursor);
		uint64_t	(*get_pfilesz)(const void *cursor);
		uint64_t	(*get_pmemsz)(const void *cursor);
		uint64_t	(*get_pflags)(const void *cursor);
		uint64_t	(*get_palign)(const void *cursor);
	//section header getter
		uint64_t	(*get_shname)(const void *cursor);
		uint64_t	(*get_shtype)(const void *cursor);
		uint64_t	(*get_shflags)(const void *cursor);
		uint64_t	(*get_shaddr)(const void *cursor);
		uint64_t	(*get_shoffset)(const void *cursor);
		uint64_t	(*get_shsize)(const void *cursor);
		uint64_t	(*get_shlink)(const void *cursor);
		uint64_t	(*get_shinfo)(const void *cursor);
		uint64_t	(*get_shaddralign)(const void *cursor);
		uint64_t	(*get_shentsize)(const void *cursor);
	//ehdr_setter
		void		(*set_entry)(void *ogn_map, uint64_t new_value);
		void		(*set_phdr_offset)(void *ogn_map, uint64_t new_value);
		void		(*set_phdr_nb)(void *ogn_map, uint64_t new_value);
		void		(*set_phdr_size)(void *ogn_map, uint64_t new_value);
		void		(*set_shdr_offset)(void *ogn_map, uint64_t new_value);
		void		(*set_shdr_nb)(void *ogn_map, uint64_t new_value);
		void		(*set_shdr_size)(void *ogn_map, uint64_t new_value);
		void		(*set_shstrndx)(void *ogn_map, uint64_t new_value);
	//phdr_setter
		void    (*set_ptype)(void *cursor, uint64_t new_value);
        void    (*set_poffset)(void *cursor, uint64_t new_value);
        void    (*set_pvaddr)(void *cursor, uint64_t new_value);
        void    (*set_ppaddr)(void *cursor, uint64_t new_value);
        void    (*set_pfilesz)(void *cursor, uint64_t new_value);
        void    (*set_pmemsz)(void *cursor, uint64_t new_value);
        void    (*set_pflags)(void *cursor, uint64_t new_value);
        void    (*set_palign)(void *cursor, uint64_t new_value);

}	t_elf_ops;

extern const t_elf_ops	ops_64;
//extern const t_elf_ops ops_32;

typedef struct	s_stub_injector
{
	void		*content_begin; //beginning of the binary content to transfer 
	uint64_t	content_size;
	void		*current_placeholder; //pointer on current first placeholder available
	uint64_t		av_addr;
	uint64_t		av_core_offset;
}	t_stub_injector;

typedef struct s_file_intel
{
	uint64_t	e_entry;
	uint64_t	phdr_offset;
	uint64_t	shdr_offset;
	uint64_t	phdr_size;
	uint64_t	shdr_size;
	uint64_t	phdr_num;
	uint64_t	shdr_num;
	uint64_t	shstrtab_index;
	char		*strtab;
	uint64_t	strtab_size;
}	t_file_intel;


typedef struct	s_bin_file
{
	char				*path;
	int					fd;
	void				*map;
	t_file_intel		*intel;
	const t_elf_ops		*elf_caster;
	uint64_t			map_size;
}	t_bin_file;

typedef struct  s_bin_data
{
	int					stoppage;
	t_bin_file				*core;
	t_bin_file				*stub;
	void					*map_copy;
	int						copy_fd;
	uint64_t				copy_size;
	const t_elf_ops			*elf_caster;
    t_stub_injector			*stub_injector;
}   t_bin_data;


//init

t_bin_data	*init(char *core_file, char *stub);


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
void    positive_pnumber(unsigned int i, int fd);

//error
void	register_error(t_bin_data *data, char *msg, t_bin_file *file);

//universal getter
bool			is_not_elf(const void *map);
bool			is_version_unvalid(const void *map);
bool			is_b_endian(const void *map);
uint64_t		get_byte_type(const void *map);

//print 
void	print_strtab(unsigned char *s, uint64_t size);
void	print_ehdr(t_bin_file *file);
void	print_both_ehdr(t_bin_data *data);

# define ft_perror(s) ft_putendl_fd(s, 2)
# define CR_DEFAULT cr(STDIN_FILENO)

//math
int		is_power_2(uint64_t x);
uint64_t	find_next_aligned_value(uint64_t value, uint64_t align);

//opener

void		compute_map_size(t_bin_data *data, t_bin_file *file);
void		open_map(t_bin_data *data);
void		open_basic_cpy(t_bin_data *data, char *s);
void		open_extend(t_bin_data *data, char *s);

//copy
void		simple_cpy(t_bin_data *data, char *s);
void		stripped_copy(t_bin_data *data, char *s);
	//stub_copy
		//free_standing stub copy
		void	fs_basic_stub_copy(t_bin_data *data);

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


//shdr_utils
	//parse
		void	shdr_range_check(t_bin_file *file, t_bin_data *data, void *aux_data, void *cursor);
	//strip
		void	strip_shdr(t_bin_file *file, t_bin_data *data);
		void	destroy_current_shdr(t_bin_file *file, t_bin_data *data, void *aux_data, void *cursor);
	//find
		char	*get_name(void *cursor, t_bin_file *file);
		void    *find_shdr_by_name(t_bin_file *file, t_bin_data *data, char *name);

//end
void	close_map(t_bin_file *file);
void	free_data(t_bin_data *data);

//stub
void    craft_stub_phdr(t_bin_data *data, void *phdr);

	//freestanding stub
	void	gather_fs_stub_data(t_bin_data *data);
	void	fs_find_canaries(t_bin_data *data, void *cursor, uint64_t size, t_stub_injector *injector);


//full fonctions, can be launched as autonomous prog or wrapper
//autonomous
int		autonomous_get_Elf_Class(char *s);
//wrapper
void	resize_after_strip(t_bin_file *file, t_bin_data *data, int fd);


# define DEFAULT_ERROR(x) ft_end(x, 1)

# endif
