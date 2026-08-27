/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 08:43:44 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/27 08:53:12 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELF_64_H
# define ELF_64_H

# include <elf.h>

//getter
    uint64_t	get_entry_64(const void *ogn_map);
    uint64_t	get_phdr_offset_64(const void *ogn_map);
    uint64_t	get_phdr_nb_64(const void *ogn_map);
    uint64_t    get_phdr_size_64(const void *ogn_map);
    uint64_t	get_shdr_offset_64(const void *ogn_map);
    uint64_t    get_shdr_size_64(const void *ogn_map);
    uint64_t    get_shstrndx_64(const void  *ogn_map);

#endif
