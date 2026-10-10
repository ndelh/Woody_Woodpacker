/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phdr_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 14:37:31 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 14:37:46 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

uint64_t	find_bss_size(const t_elf_ops *elf_caster, void *cursor)
{
	return (elf_caster->get_pmemsz(cursor) - elf_caster->get_pfilesz(cursor));
}

void    retrieve_farthest_phdr_physical(t_bin_file *file, void *aux_data, void *cursor)
{
    uint64_t    *longest;
    uint64_t    current_end_of_use;

    if (!(file->elf_caster->get_pmemsz(cursor)))
        return ;
    longest = (uint64_t *)aux_data;
    current_end_of_use = file->elf_caster->get_poffsset(cursor) + file->elf_caster->get_pfilesz(cursor) - 1;
    if (current_end_of_use > *longest)
        *longest = current_end_of_use;
}

uint64_t   retrieve_farthest_needed_point(t_bin_file *file)
{
    uint64_t to_ret;
    uint64_t farthest;

    farthest = 0;
    to_ret = file->intel->phdr_offset + (file->intel->phdr_num * file->intel->phdr_offset) - 1;
    iter_phdr(file, &farthest, retrieve_farthest_phdr_physical);
    if (farthest > to_ret)
        to_ret = farthest;
    return (to_ret);
}