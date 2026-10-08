/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ehdr_setter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:40:43 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 12:41:22 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../elf_64.h"

void	set_entry_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Ehdr *)ogn_map)->e_entry = new_value;
}

void	set_phdr_offset_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Ehdr *)ogn_map)->e_phoff = new_value;
}

void	set_phdr_nb_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Ehdr *)ogn_map)->e_phnum = new_value;
}

void	set_phdr_size_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Ehdr *)ogn_map)->e_phentsize = new_value;
}

void	set_shdr_offset_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Ehdr *)ogn_map)->e_shoff = new_value;
}

void	set_shdr_nb_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Ehdr *)ogn_map)->e_shnum = new_value;
}

void	set_shdr_size_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Ehdr *)ogn_map)->e_shentsize = new_value;
}

void	set_shstrndx_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Ehdr *)ogn_map)->e_shstrndx = new_value;
}
