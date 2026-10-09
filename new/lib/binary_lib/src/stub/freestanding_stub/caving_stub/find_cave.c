/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_available_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 16:57:09 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/13 16:57:48 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

typedef struct s_cave
{
    void        *to_cave;
    uint64_t    stub_size;
    bool        exec_possible; //define in we can cave in the original segment with exec write;
}   t_cave;

uint64_t    count_blank(t_bin_file *file, const t_elf_ops *elf_caster, void *cursor)
{
    uint64_t        count_blank;
    uint64_t        bss_size;
    unsigned char   *iterator;
    unsigned char   *end;

    iterator = (unsigned char *)file->map;
    end = (unsigned char *)file->map + file->map_size;
    iterator += elf_caster->get_poffsset(cursor) + elf_caster->get_pfilesz(cursor);
    count_blank = 0;
    while ((iterator != end) && !(*iterator))
    {
        ++count_blank;
        ++iterator;
    }
    bss_size = find_bss_size(elf_caster, cursor);
    if (count_blank <= bss_size)
        return (0);
    count_blank -= bss_size;
    return count_blank;
}

void    ite_find_cave(t_bin_file *file, void *helper, void *cursor)
{
    const t_elf_ops *elf_caster;
    uint64_t        blank_count;
    uint64_t        bss_size;

    elf_caster = file->elf_caster;
    if (elf_caster->get_ptype(cursor) != PT_LOAD || ((t_cave *)helper)->exec_possible)
        return ;
    blank_count = count_blank(file, elf_caster, cursor);
    bss_size = find_bss_size(elf_caster, cursor);
    if (blank_count <= ((t_cave *)helper)->stub_size + bss_size)
        return ;
    ((t_cave *)helper)->to_cave = cursor;
    if (elf_caster->get_pflags(cursor) == (PF_X | PF_R)) //we want to favor the exec phdr
        ((t_cave *)helper)->exec_possible = 1;
}

void    *find_cave(t_bin_file *file, uint64_t stub_size)
{
    t_cave  cave;

    ft_bzero(&cave, sizeof(t_cave));
    cave.stub_size = stub_size;
    iter_phdr(file, &cave, ite_find_cave);
    if (cave.to_cave == NULL)
        file_warning("unable to use caving technique, remaining place is unsufficient", file);
    return (cave.to_cave);
}