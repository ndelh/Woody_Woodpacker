/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phdr_getter_64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:39:32 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/04 16:41:05 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../elf_64.h"

uint64_t	get_ptype_64(const void *cursor)
{
	return (((const Elf64_Phdr *)cursor)->p_type);
}

uint64_t	get_poffset_64(const void *cursor)
{	
	return (((const Elf64_Phdr *)cursor)->p_offset);
}

uint64_t	get_pvaddr_64(const void *cursor)
{	
	return (((const Elf64_Phdr *)cursor)->p_vaddr);
}

uint64_t	get_paddr_64(const void *cursor)
{	
	return (((Elf64_Phdr *)cursor)->p_paddr);
}

uint64_t	get_pfilesz_64(const void *cursor)
{
	return (((Elf64_Phdr *)cursor)->p_filesz);
}

uint64_t	get_pmemsz_64(const void *cursor)
{
	return (((const Elf64_Phdr *)cursor)->p_memsz);
}

uint64_t	get_pflags_64(const void *cursor)
{
	return (((const Elf64_Phdr *)cursor)->p_flags);
}

uint64_t	get_palign_64(const void *cursor)
{
	return (((const Elf64_Phdr *)cursor)->p_align);
}