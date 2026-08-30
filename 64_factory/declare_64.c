/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 11:44:38 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/27 11:45:24 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"
#include "elf_64.h"

const	t_elf_ops   ops_64 = {
    .get_entry = get_entry_64,
    .get_phdr_offset = get_phdr_offset_64,
    .get_phdr_nb = get_phdr_nb_64,
    .get_phdr_size = get_phdr_size_64,
    .get_shdr_offset = get_shdr_offset_64,
    .get_shdr_nb = get_shdr_nb_64,
    .get_shdr_size = get_shdr_size_64,
    .get_shstrndx = get_shstrndx_64,
    .get_ptype = get_ptype_64,
    .get_poffsset = get_poffset_64,
    .get_pvaddr = get_pvaddr_64,
    .get_paddr = get_paddr_64,
    .get_pfilesz = get_pfilesz_64,
    .get_pmemsz = get_pmemsz_64,
    .get_pflags = get_pflags_64,
    .get_palign = get_palign_64,
};
