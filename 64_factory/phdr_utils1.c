/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phdr_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:05:50 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/27 15:12:04 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elf_64.h"

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
