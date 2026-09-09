/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phdr_setter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 08:37:10 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/09 08:37:21 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	set_ptype_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Phdr *)ogn_map)->p_type = new_value;
}

void	set_poffset_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Phdr *)ogn_map)->p_offset = new_value;
}

void	set_pvaddr_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Phdr *)ogn_map)->p_vaddr = new_value;
}

void	set_ppaddr_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Phdr *)ogn_map)->p_paddr = new_value;
}

void	set_pfilesz_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Phdr *)ogn_map)->p_filesz = new_value;
}

void	set_pmemsz_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Phdr *)ogn_map)->p_memsz = new_value;
}

void	set_pflags_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Phdr *)ogn_map)->p_flags = new_value;
}

void	set_palign_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Phdr *)ogn_map)->p_align = new_value;
}