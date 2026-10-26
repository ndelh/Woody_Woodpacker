/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:55:10 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/25 12:23:39 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elf_32.h"

const	t_elf_ops   ops_32 = {
    //ehdr getter
    .get_entry = get_entry_32,
    .get_ehsize = get_ehsize_32,
    .get_phdr_offset = get_phdr_offset_32,
    .get_phdr_nb = get_phdr_nb_32,
    .get_phdr_size = get_phdr_size_32,
    .get_shdr_offset = get_shdr_offset_32,
    .get_shdr_nb = get_shdr_nb_32,
    .get_shdr_size = get_shdr_size_32,
    .get_shstrndx = get_shstrndx_32,
    //phdr getter
    .get_ptype = get_ptype_32,
    .get_poffsset = get_poffset_32,
    .get_pvaddr = get_pvaddr_32,
    .get_paddr = get_paddr_32,
    .get_pfilesz = get_pfilesz_32,
    .get_pmemsz = get_pmemsz_32,
    .get_pflags = get_pflags_32,
    .get_palign = get_palign_32,
    //shdr getter
    .get_shname = get_sh_name_32,
    .get_shtype = get_sh_type_32,
    .get_shflags = get_sh_flags_32,
    .get_shaddr = get_sh_addr_32,
    .get_shoffset = get_sh_offset_32,
    .get_shsize = get_sh_size_32,
    .get_shlink = get_sh_link_32,
    .get_shinfo = get_sh_info_32,
    .get_shaddralign = get_sh_addralign_32,
    .get_shentsize = get_sh_entsize_32,
    //ehdr setter
    .set_entry = set_entry_32,
    .set_phdr_offset = set_phdr_offset_32,
    .set_phdr_nb = set_phdr_nb_32,
    .set_phdr_size = set_phdr_size_32,
    .set_shdr_offset = set_shdr_offset_32,
    .set_shdr_nb = set_shdr_nb_32,
    .set_shdr_size = set_shdr_size_32,
    .set_shstrndx = set_shstrndx_32,
    //phdr setter
    .set_ptype = set_ptype_32,
    .set_poffset = set_poffset_32,
    .set_pvaddr = set_pvaddr_32,
    .set_ppaddr = set_ppaddr_32,
    .set_pfilesz = set_pfilesz_32,
    .set_pmemsz = set_pmemsz_32,
    .set_pflags = set_pflags_32,
    .set_palign = set_palign_32,
    //shdr setter
    .set_sh_name = set_sh_name_32,
    .set_sh_type = set_sh_type_32,
    .set_sh_flags = set_sh_flags_32,
    .set_sh_addr = set_sh_addr_32,
    .set_sh_offset = set_sh_offset_32,
    .set_sh_size = set_sh_size_32,
    .set_sh_link = set_sh_link_32,
    .set_sh_info = set_sh_info_32,
    .set_sh_addralign = set_sh_addralign_32,
    .set_sh_entsize = set_sh_entsize_32,
};
