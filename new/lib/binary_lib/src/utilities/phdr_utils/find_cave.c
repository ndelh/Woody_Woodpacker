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
    uint64_t    bss_size;
    bool        exec_possible; //define in we can cave in the original segment with exec write;
}   t_cave;

uint64_t    count_blank(unsigned char *map, const t_elf_ops *elf_caster, void *cursor)
{
    uint64_t        count_blank;
    unsigned char   *iterator;

    iterator = map;
    iterator += elf_caster->get_poffsset(cursor) + elf_caster->get_pmemsz(cursor);
    count_blank = 0;
    while (!(*iterator))
    {
        ++count_blank;
        ++iterator;
    }
    return count_blank;
}

void    ite_find_cave(t_bin_file *file, t_bin_data *data, void *helper, void *cursor)
{
    const t_elf_ops *elf_caster;
    uint64_t        blank_count;
    uint64_t        current_bss;

    elf_caster = file->elf_caster;
    if (elf_caster->get_ptype(cursor) != PT_LOAD || ((t_cave *)helper)->exec_possible)
        return ;
    blank_count = count_blank(file->map, elf_caster, cursor);
    current_bss = find_bss_size(elf_caster, cursor);
    if (blank_count <= data->stub_injector->content_size)
        return ;
    if (elf_caster->get_pflags(cursor) == (PF_X | PF_R))
    {
        ((t_cave *)helper)->exec_possible = 1;
        ((t_cave *)helper)->to_cave = cursor;
    }
    else if (current_bss < ((t_cave *)helper)->bss_size)
    {
        ((t_cave *)helper)->bss_size = current_bss;
        ((t_cave *)helper)->to_cave = cursor;
    }
}

void    *find_cave(t_bin_file *file, t_bin_data *data)
{
    t_cave  cave;

    ft_bzero(&cave, sizeof(t_cave));
    cave.bss_size = UINT64_MAX;
    iterate_phdr(file, data, &cave, ite_find_cave);
    return (cave.to_cave);
}