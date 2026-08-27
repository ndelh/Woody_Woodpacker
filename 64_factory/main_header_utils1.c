/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 08:54:53 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/27 09:09:37 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elf_64.h"

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
