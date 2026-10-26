/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_32.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:22:40 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/25 12:23:34 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/binary_lib.h"


#ifndef ELF_32_H
# define ELF_32_H


//getter
    //main header
        uint64_t	get_entry_32(const void *ogn_map);
        uint64_t    get_ehsize_32(const void *ogn_map);
        uint64_t	get_phdr_offset_32(const void *ogn_map);
        uint64_t	get_phdr_nb_32(const void *ogn_map);
        uint64_t    get_phdr_size_32(const void *ogn_map);
        uint64_t	get_shdr_offset_32(const void *ogn_map);
        uint64_t    get_shdr_nb_32(const void *ogn_map);
        uint64_t    get_shdr_size_32(const void *ogn_map);
        uint64_t    get_shstrndx_32(const void  *ogn_map);
    //program header
        uint64_t    get_ptype_32(const void *cursor);
        uint64_t    get_poffset_32(const void *cursor);
        uint64_t    get_pvaddr_32(const void *cursor);
        uint64_t    get_paddr_32(const void *cursor);
        uint64_t    get_pfilesz_32(const void *cursor);
        uint64_t    get_pmemsz_32(const void *cursor);
        uint64_t    get_pflags_32(const void *cursor);
        uint64_t    get_palign_32(const void *cursor);
    //section header
        uint64_t	get_sh_name_32(const void *cursor);
        uint64_t	get_sh_type_32(const void *cursor);
        uint64_t	get_sh_flags_32(const void *cursor);
        uint64_t	get_sh_addr_32(const void *cursor);
        uint64_t	get_sh_offset_32(const void *cursor);
        uint64_t	get_sh_size_32(const void *cursor);
        uint64_t	get_sh_link_32(const void *cursor);
        uint64_t	get_sh_info_32(const void *cursor);
        uint64_t	get_sh_addralign_32(const void *cursor);
        uint64_t	get_sh_entsize_32(const void *cursor);
//setter
    //main header
        void    set_entry_32(void *ogn_map, uint64_t new_value);
        void    set_phdr_offset_32(void *ogn_map, uint64_t new_value);
        void    set_phdr_nb_32(void *ogn_map, uint64_t new_value);
        void    set_phdr_size_32(void *ogn_map, uint64_t new_value);
        void    set_shdr_offset_32(void *ogn_map, uint64_t new_value);
        void    set_shdr_nb_32(void *ogn_map, uint64_t new_value);
        void    set_shdr_size_32(void *ogn_map, uint64_t new_value);
        void    set_shstrndx_32(void *ogn_map, uint64_t new_value);
    //program header
        void    set_ptype_32(void *cursor, uint64_t new_value);
        void    set_poffset_32(void *cursor, uint64_t new_value);
        void    set_pvaddr_32(void *cursor, uint64_t new_value);
        void    set_ppaddr_32(void *cursor, uint64_t new_value);
        void    set_pfilesz_32(void *cursor, uint64_t new_value);
        void    set_pmemsz_32(void *cursor, uint64_t new_value);
        void    set_pflags_32(void *cursor, uint64_t new_value);
        void    set_palign_32(void *cursor, uint64_t new_value);
    //section header
        void	set_sh_name_32(void *cursor, uint64_t new_value);
        void	set_sh_type_32(void *cursor, uint64_t new_value);
        void	set_sh_flags_32(void *cursor, uint64_t new_value);
        void	set_sh_addr_32(void *cursor, uint64_t new_value);
        void	set_sh_offset_32(void *cursor, uint64_t new_value);
        void	set_sh_size_32(void *cursor, uint64_t new_value);
        void	set_sh_link_32(void *cursor, uint64_t new_value);
        void	set_sh_info_32(void *cursor, uint64_t new_value);
        void	set_sh_addralign_32(void *cursor, uint64_t new_value);
        void	set_sh_entsize_32(void *cursor, uint64_t new_value);
    
#endif
