/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:22:40 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 12:24:01 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/binary_lib.h"


#ifndef ELF_64_H
# define ELF_64_H


//getter
    //main header
        uint64_t	get_entry_64(const void *ogn_map);
        uint64_t	get_phdr_offset_64(const void *ogn_map);
        uint64_t	get_phdr_nb_64(const void *ogn_map);
        uint64_t    get_phdr_size_64(const void *ogn_map);
        uint64_t	get_shdr_offset_64(const void *ogn_map);
        uint64_t    get_shdr_nb_64(const void *ogn_map);
        uint64_t    get_shdr_size_64(const void *ogn_map);
        uint64_t    get_shstrndx_64(const void  *ogn_map);
    //program header
        uint64_t    get_ptype_64(const void *cursor);
        uint64_t    get_poffset_64(const void *cursor);
        uint64_t    get_pvaddr_64(const void *cursor);
        uint64_t    get_paddr_64(const void *cursor);
        uint64_t    get_pfilesz_64(const void *cursor);
        uint64_t    get_pmemsz_64(const void *cursor);
        uint64_t    get_pflags_64(const void *cursor);
        uint64_t    get_palign_64(const void *cursor);
    //section header
        uint64_t	get_sh_name_64(const void *cursor);
        uint64_t	get_sh_type_64(const void *cursor);
        uint64_t	get_sh_flags_64(const void *cursor);
        uint64_t	get_sh_addr_64(const void *cursor);
        uint64_t	get_sh_offset_64(const void *cursor);
        uint64_t	get_sh_size_64(const void *cursor);
        uint64_t	get_sh_link_64(const void *cursor);
        uint64_t	get_sh_info_64(const void *cursor);
        uint64_t	get_sh_addralign_64(const void *cursor);
        uint64_t	get_sh_entsize_64(const void *cursor);
//setter
    //main header
        void    set_entry_64(void *ogn_map, uint64_t new_value);
        void    set_phdr_offset_64(void *ogn_map, uint64_t new_value);
        void    set_phdr_nb_64(void *ogn_map, uint64_t new_value);
        void    set_phdr_size_64(void *ogn_map, uint64_t new_value);
        void    set_shdr_offset_64(void *ogn_map, uint64_t new_value);
        void    set_shdr_nb_64(void *ogn_map, uint64_t new_value);
        void    set_shdr_size_64(void *ogn_map, uint64_t new_value);
        void    set_shstrndx_64(void *ogn_map, uint64_t new_value);
    
#endif