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
		
}	t_elf_ops;

extern const t_elf_ops	ops_64;
//extern const t_elf_ops ops_32;

typedef struct	s_stub_injector
{
	void		*shdr_header_inject;
	void		*content_begin;
	void		*placeholder_begin;
	uint64_t	content_size;
	uint64_t		av_addr;
	uint64_t		stub_content_offset;
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
}	t_file_intel;


typedef struct	s_bin_file
{
	char			*path;
	int				fd;
	void			*map;
	t_file_intel	*intel;
	uint64_t		map_size;
}	t_bin_file;

typedef struct  s_bin_data
{
	t_bin_file				*core;
	t_bin_file				*stub;
	const t_elf_ops			*elf_caster;
    t_stub_injector			*stub_injector;
}   t_bin_data;


//test
void    test(void);


//boundary_check
bool	is_struct_oob(t_bin_file *intel, uint64_t offset, uint64_t struct_nb, uint64_t struct_size);
bool	is_strtab_unvalid(unsigned char *s, size_t len);


//libft

int		ft_strlen(char *s);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s1, size_t n);
void	cr(int fd);

//universal getter
bool			is_not_elf(const void *map);
bool			is_version_unvalid(const void *map);
bool			is_b_endian(const void *map);
uint64_t		get_byte_type(const void *map);

# define ft_perror(s) ft_putendl_fd(s, 2)
# define CR_DEFAULT cr(STDIN_FILENO)

//opener

void		compute_map_size(t_bin_data *data);
void		open_map(t_bin_data *data);

//parser
void		parse_first_header(t_bin_data *data);
void		parse_content_range(t_bin_data *data);

//gather
void		gather_content(t_bin_data *data);

//iterate
void	iterate_shdr(t_bin_file *file, t_bin_data *data, void(*func)(t_bin_file *file, t_bin_data *data, void *));
void	iterate_phdr(t_bin_file *file, t_bin_data *data, void(*func)(t_bin_file *file, t_bin_data *data, void *));

//end
void	ft_end(t_bin_data *data, int error_code);
void	ft_end_msg(t_bin_data *data, int error_code, char *msg);
# define DEFAULT_ERROR(x) ft_end(x, 1)

# endif
