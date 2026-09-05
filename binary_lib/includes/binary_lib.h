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

typedef struct	s_stub_injector
{
	void		*shdr_header_inject;
	void		*content_begin;
	void		*placeholder_begin;
	uint64_t	content_size;
	uint64_t		av_addr;
	uint64_t		stub_content_offset;
}	t_stub_injector;

typedef struct	s_bin_intel
{
	unsigned char	*path;
	void		*map;
	uint64_t	map_size;

}	t_bin_intel;

typedef struct  t_bin_lib
{
	t_bin_intel     *core;
	t_bin_intel     *stub;
	//t_elf_ops	*elf_caster;
    t_stub_injector   *stub_injector;
}   s_bin_lib;

//test
void    test(void);

# endif
