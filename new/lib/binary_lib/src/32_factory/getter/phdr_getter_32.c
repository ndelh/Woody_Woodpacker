/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phdr_getter_32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:39:32 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/04 16:41:05 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../elf_32.h"

uint64_t	get_ptype_32(const void *cursor)
{
	return (((const Elf32_Phdr *)cursor)->p_type);
}

uint64_t	get_poffset_32(const void *cursor)
{	
	return (((const Elf32_Phdr *)cursor)->p_offset);
}

uint64_t	get_pvaddr_32(const void *cursor)
{	
	return (((const Elf32_Phdr *)cursor)->p_vaddr);
}

uint64_t	get_paddr_32(const void *cursor)
{	
	return (((Elf32_Phdr *)cursor)->p_paddr);
}

uint64_t	get_pfilesz_32(const void *cursor)
{
	return (((Elf32_Phdr *)cursor)->p_filesz);
}

uint64_t	get_pmemsz_32(const void *cursor)
{
	return (((const Elf32_Phdr *)cursor)->p_memsz);
}

uint64_t	get_pflags_32(const void *cursor)
{
	return (((const Elf32_Phdr *)cursor)->p_flags);
}

uint64_t	get_palign_32(const void *cursor)
{
	return (((const Elf32_Phdr *)cursor)->p_align);
}