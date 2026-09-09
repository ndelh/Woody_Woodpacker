/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_vaddr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 04:51:32 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/09 04:51:55 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"


void    iter_get_current_max_vaddr(t_bin_file *file, t_bin_data *data, void *aux_data, void *cursor)
{
    const t_elf_ops     *elf_caster;
    uint64_t            current_phdr_max_vaddr;

    (void)data;
    elf_caster = file->elf_caster;
    if (elf_caster->get_ptype(cursor) != PT_LOAD)
        return ;
    current_phdr_max_vaddr = elf_caster->get_pmemsz(cursor) + elf_caster->get_pvaddr(cursor) - 1;
    if (current_phdr_max_vaddr > *((uint64_t *)aux_data))
        *((uint64_t *)aux_data) = current_phdr_max_vaddr;
}

uint64_t    get_next_available_vaddr(t_bin_file *file, t_bin_data *data)
{
    uint64_t    max_vaddr;
    uint64_t    next_available_vaddr;
    
    max_vaddr = 0;
    iterate_phdr(file, data, &max_vaddr, iter_get_current_max_vaddr);
    if (!max_vaddr)
    {
        register_error(data, "no pt_load found or fallacious pt_load", file);
        return (0);
    }
    next_available_vaddr = find_next_aligned_value(max_vaddr, PAGESIZE);
    if (!next_available_vaddr)
        register_error(data, "cannot found next available addr, this can be due to a non ^2 Pagesize or an overflow prevention", file);
    printf("next available vaddr found is hex: %lx, not hex %lu\n", next_available_vaddr, next_available_vaddr);
    return (next_available_vaddr);
}