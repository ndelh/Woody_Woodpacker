/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_longest_values.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 07:57:07 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/07 08:01:55 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void    retrieve_farthest_phdr_physical(t_bin_file *file, t_bin_data *data, void *aux_data, void *cursor)
{
    uint64_t    *longest;
    uint64_t    current_end_of_use;

    (void)data;
    if (!(file->elf_caster->get_pmemsz(cursor)))
        return ;
    longest = (uint64_t *)aux_data;
    current_end_of_use = file->elf_caster->get_poffsset(cursor) + file->elf_caster->get_pmemsz(cursor) - 1;
    if (current_end_of_use > *longest)
        *longest = current_end_of_use;
}

uint64_t   retrieve_farthest_physical(t_bin_file *file, t_bin_data *data)
{
    uint64_t to_ret;
    uint64_t farthest;

    farthest = 0;
    to_ret = file->intel->phdr_offset + (file->intel->phdr_num * file->intel->phdr_offset) - 1;
    iterate_phdr(file, data, &farthest, retrieve_farthest_phdr_physical);
    if (farthest > to_ret)
        to_ret = farthest;
    return (to_ret);
}
