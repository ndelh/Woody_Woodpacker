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

uint64_t    count_blank(unsigned char *map, const t_elf_ops *elf_caster, void *cursor)
{
    uint64_t        count_blank;
    unsigned char   *iterator;

    iterator = map;
    iterator += elf_caster->get_poffsset(cursor) + elf_caster->get_pfilesz(cursor);
    count_blank = 0;
    while (!(*iterator))
    {
        ++count_blank;
        ++iterator;
    }
    return count_blank;
}

// bool    is_cave_valid(t_bin_file *file, t_bin_data *data, void *helper, void *cave_candidate)
// {
//     const t_elf_ops *elf_caster;
//     uint64_t    supposed_memsz_end;

//     elf_caster = file->elf_caster;
//     supposed_memsz_end = elf_caster->get_pmemsz(cave_candidate) + data->stub->

// }

void    ite_find_cave(t_bin_file *file, t_bin_data *data, void *helper, void *cursor)
{
    const t_elf_ops *elf_caster;
    uint64_t        blank_count;

    elf_caster = file->elf_caster;
    if (elf_caster->get_ptype(cursor) != PT_LOAD || ((t_cave *)helper)->exec_possible)
        return ;
    blank_count = count_blank(file->map, elf_caster, cursor);
    if (blank_count <= data->stub_injector->content_size)
        return ;
    ((t_cave *)helper)->to_cave = cursor;
    if (elf_caster->get_pflags(cursor) == (PF_X | PF_R)) //we want to favor the exec phdr
        ((t_cave *)helper)->exec_possible = 1;
}

void    *find_cave(t_bin_file *file, t_bin_data *data)
{
    t_cave  cave;

    ft_bzero(&cave, sizeof(t_cave));
    cave.stub_size = data->stub_injector->content_size;
    iterate_phdr(file, data, &cave, ite_find_cave);
    if (cave.to_cave == NULL)
        register_error(data, "unable to use caving technique, remaining place is unsufficient", data->core);
    return (cave.to_cave);
}