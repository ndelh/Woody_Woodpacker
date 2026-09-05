/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phdr_wrapped_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:05:15 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/01 14:09:32 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"

uint64_t    count_loop_extension(unsigned char *cursor,uint64_t phdr_size, unsigned char *eof)
{
    uint64_t    empty_spaces;

    if ((uint64_t)(eof - cursor) < phdr_size || *cursor)
        return (0);
    empty_spaces = 0;
    while (cursor < eof && *cursor == 0)
    {
        ++cursor;
        ++empty_spaces;
    }
    return (empty_spaces / phdr_size);
}

uint64_t     extension_space(t_intel *intel)
{
    unsigned char               *cursor;
    unsigned char               *eof;
    uint64_t                    count;
    uint64_t                    phdr_size;

    phdr_size = intel->bin_data.phdr_size;
    cursor = (unsigned char *)intel->ogn_begin;
    eof = cursor + intel->ogn_size;
    cursor += intel->bin_data.phdr_offset;
    cursor += intel->bin_data.phdr_num * phdr_size;
    count = count_loop_extension(cursor, phdr_size, eof);
    return (count);
}

void    retrieve_available_adrr(t_intel *intel, void *cursor)
{
    uint64_t    next_av_addr;

    if (intel->elf_caster->get_ptype(cursor) != PT_LOAD)
        return ;
    next_av_addr = intel->elf_caster->get_pvaddr(cursor) + intel->elf_caster->get_pmemsz(cursor);
    if (next_av_addr > intel->stub_loader.av_addr)
        intel->stub_loader.av_addr = next_av_addr;
}

void    align_available_adress(t_intel *intel)
{
    uint64_t    adress_align;

    adress_align = intel->stub_loader.av_addr;
    adress_align = (adress_align + 0xFFF) & ~0xFFFULL;
    intel->stub_loader.av_addr = adress_align;
}