/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ehdr_getter_64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:34:21 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 12:36:30 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../elf_64.h"

uint64_t	get_entry_64(const void *ogn_map)
{
	return (((const Elf64_Ehdr *)ogn_map)->e_entry);
}

uint64_t	get_phdr_offset_64(const void *ogn_map)
{
	return (((const Elf64_Ehdr *)ogn_map)->e_phoff);
}

uint64_t	get_phdr_nb_64(const void *ogn_map)
{
	return (((const Elf64_Ehdr *)ogn_map)->e_phnum);
}

uint64_t	get_shdr_offset_64(const void *ogn_map)
{
	return (((const Elf64_Ehdr *)ogn_map)->e_shoff);
}

uint64_t	get_shdr_nb_64(const void *ogn_map)
{
	return (((const Elf64_Ehdr *)ogn_map)->e_shnum);
}

uint64_t	get_phdr_size_64(const void *ogn_map)
{
	return (((const Elf64_Ehdr *)ogn_map)->e_phentsize);
}

uint64_t	get_shdr_size_64(const void *ogn_map)
{
	return (((const Elf64_Ehdr *)ogn_map)->e_shentsize);
}

uint64_t	get_shstrndx_64(const void *ogn_map)
{
	return (((const Elf64_Ehdr *)ogn_map)->e_shstrndx);
}