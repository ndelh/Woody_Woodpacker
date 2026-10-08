/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:55:03 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/08 14:58:28 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_elf_ops
{
	//ehdr_getter
		uint64_t	(*get_entry)(const void *ogn_map);
		uint64_t	(*get_phdr_offset)(const void *ogn_map);
		uint64_t	(*get_phdr_nb)(const void *ogn_map);
		uint64_t	(*get_phdr_size)(const void *ogn_map);
		uint64_t	(*get_shdr_offset)(const void *ogn_map);
		uint64_t	(*get_shdr_nb)(const void *ogn_map);
		uint64_t	(*get_shdr_size)(const void *ogn_map);
		uint64_t	(*get_shstrndx)(const void *ogn_map);
	//phdr_getter
		uint64_t	(*get_ptype)(const void *cursor);
		uint64_t	(*get_poffsset)(const void *cursor);
		uint64_t	(*get_pvaddr)(const void *cursor);
		uint64_t	(*get_paddr)(const void *cursor);
		uint64_t	(*get_pfilesz)(const void *cursor);
		uint64_t	(*get_pmemsz)(const void *cursor);
		uint64_t	(*get_pflags)(const void *cursor);
		uint64_t	(*get_palign)(const void *cursor);
	//shdr_getter
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
	//shdr_setter
		void	(*set_sh_name)(void *cursor, uint64_t new_value);
        	void	(*set_sh_type)(void *cursor, uint64_t new_value);
        	void	(*set_sh_flags)(void *cursor, uint64_t new_value);
        	void	(*set_sh_addr)(void *cursor, uint64_t new_value);
        	void	(*set_sh_offset)(void *cursor, uint64_t new_value);
        	void	(*set_sh_size)(void *cursor, uint64_t new_value);
        	void	(*set_sh_link)(void *cursor, uint64_t new_value);
        	void	(*set_sh_info)(void *cursor, uint64_t new_value);
        	void	(*set_sh_addralign)(void *cursor, uint64_t new_value);
		void	(*set_sh_entsize)(void *cursor, uint64_t new_value);

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
	const t_elf_ops		*elf_caster;
	t_file_intel		*intel;
	uint64_t			map_size;
	bool				dead;
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


#endif
