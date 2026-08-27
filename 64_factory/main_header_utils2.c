/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 09:11:35 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/27 09:22:37 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elf_64.h"

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
