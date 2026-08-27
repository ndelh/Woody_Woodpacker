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
	uint64_t	phdr_offset;
	uint64_t	phdr_num;
	uint64_t	phdr_size;
	uint64_t	shdr_offset;
	uint64_t	shdr_num;
	uint64_t	shdr_size;
	uint64_t	shstrndx;
}	t_elf_navigator;


typedef struct	s_intel
{
	uint64_t				ogn_size;
	void					*ogn_begin;
	char					*binary_name;
	const struct s_elf_ops	*elf_caster;
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
	uint64_t	(*get_shstrndx)(const void *ogn_map);

}	t_elf_ops;

//extern const t_elf_ops	ops_32;
extern const t_elf_ops		ops_64;

//utilitaries
	//pure utils
	int		ft_strlen(char *s);
	void	ft_bzero(void *s, size_t n);
	int	ft_memcmp(const void *s1, const void *s2, size_t n);
	//print_utils
	void	ft_putendl_fd(char *s, int fd);
	void	cr(int fd);
		//printf wrapper
			void	print_int(char *s, int i);
	//boundary check
	bool	is_offset_in_range(t_intel *intel, uint64_t offset);
	//binary intel related utils
	void	retrieve_lpad(t_lpad *lpad, t_intel *intel);


//init
	//map_init
	void	retrieve_ogn_map(char *s, t_intel *intel);
	//is_file_valid
	int	check_prerequisite(t_intel *intel);

//core
void	modify_core(t_intel *intel);

#endif 
