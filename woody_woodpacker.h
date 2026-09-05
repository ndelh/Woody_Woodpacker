/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody_woodpacker.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:09:17 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/20 15:56:36 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOODY_WOODPACKER_H
# define WOODY_WOODPACKER_H

# define ft_perror(x) ft_putendl_fd(x, 2)
# define STUBNAME "stub"
# define PLACEHOLDERNB	5
# define PAGESIZE 4096
#define PLACEHOLDER 0x1122334455667788ULL

# include <sys/syscall.h>
# include <sys/mman.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <elf.h>
# include <stdbool.h>

typedef struct s_elf_navigator
{
	uint64_t	entry;
	uint64_t	phdr_offset;
	uint64_t	phdr_num;
	uint64_t	phdr_size;
	uint64_t	shdr_offset;
	uint64_t	shdr_num;
	uint64_t	shdr_size;
	uint64_t	shstrndx;
	unsigned char	*strtab_begin;
	uint64_t		strtab_len;
}	t_elf_navigator;

typedef struct	s_stub_loader
{
	void		*shdr_header_inject;
	void		*content_begin;
	void		*placeholder_begin;
	uint64_t	content_size;
	uint64_t		av_addr;
	uint64_t		stub_content_offset;
}	t_stub_loader;


typedef struct	s_intel
{
	uint64_t				ogn_size;
	void					*ogn_begin;
	char					*binary_name;
	const struct s_elf_ops	*elf_caster;
	struct s_stub_loader	stub_loader;
	t_elf_navigator			bin_data;
}	t_intel;

typedef struct s_lpad
{
	int	len;
	int offset;
}	t_lpad;


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
	//modifier
		void		(*write_stub_phdr)(t_intel *intel, void *cursor);

}	t_elf_ops;

//extern const t_elf_ops	ops_32;
extern const t_elf_ops		ops_64;

//utilitaries
	
	//pure utils
	int		ft_strlen(char *s);
	void	ft_bzero(void *s, size_t n);
	int		ft_memcmp(const void *v1, const void *v2, size_t n);
	void	ft_memcpy(void *dest, const void *src, size_t n);
	
	//print_utils
	void	ft_putendl_fd(char *s, int fd);
	void	cr(int fd);
	
		//printf wrapper
			void	print_int(char *s, int i);
	
	//boundary check
		bool	is_strtab_invalid(unsigned char * s, size_t len);
		bool	is_offset_oob(t_intel *intel, uint64_t offset);
		bool	is_struct_oob(t_intel *intel, uint64_t offset, uint64_t struct_nb, uint64_t struct_size);
	
	//iter throught section
		void	iterate_phdr(t_intel *intel, void(*func)(t_intel *, void *));
		void	iterate_shdr(t_intel *intel, void(*func)(t_intel *intel, void *));
	
	//binary intel related utils
		void			retrieve_lpad(t_lpad *lpad, t_intel *intel);
		unsigned char	*retrieve_shdr_name(t_intel *intel, void *cursor);
		uint64_t     	extension_space(t_intel *intel);
		bool			retrieve_placeholder(t_intel *intel);
	//data acquisition for merging binaires
		void			fetch_modify_need(t_intel *intel, t_intel *stub);
		void    		align_available_adress(t_intel *intel);
		void			retrieve_available_adrr(t_intel *intel, void *cursor);

//init

	//map_init
	void	retrieve_ogn_map(char *s, t_intel *intel);

	//is_file_valid
	int	check_prerequisite(t_intel *intel);

//core
void	modify_core(t_intel *intel);

	//intel retrieve
		void	gather_ehdr(t_intel *intel);
		void	gather_stub_intel(t_intel *intel, t_intel *stub);
		void	retrieve_txt_shdr(t_intel *intel, void *cursor);
		bool	retrieve_strtab(t_intel *intel);
	
	//modifier
		void	shdr_destruct(t_intel *intel, void *cursor);
		void	reproduce(t_intel *intel);

//debug
	void	print_edhr_intel(t_intel *intel);
	void	print_phdr_intel(t_intel *intel, void *cursor);
	void	print_strtab(t_intel *intel);

//end
void	error_end(char *msg, int code, t_intel *intel);

#endif 
