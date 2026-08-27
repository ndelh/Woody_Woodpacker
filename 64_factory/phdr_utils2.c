/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phdr_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:15:11 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/27 15:18:24 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elf_64.h"

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
