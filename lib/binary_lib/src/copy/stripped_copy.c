/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripped_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 05:37:00 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/09 05:37:59 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void    add_new_empty_shdr(t_bin_data *data, uint64_t shdr_size)
{   
    unsigned char       *shdr_cursor;

    const   t_elf_ops   *elf_caster;

    elf_caster = data->core->elf_caster;
    shdr_cursor = (unsigned char *)data->map_copy + data->copy_size - 1;
    ft_bzero(shdr_cursor, shdr_size * 2);
    shdr_cursor += shdr_size;
    elf_caster->set_sh_type(shdr_cursor, SHT_STRTAB);
    elf_caster->set_sh_size(shdr_cursor, 1);
    elf_caster->set_sh_offset(shdr_cursor, data->copy_size); // a lil bit barbaric used to point to a \0
}
void	stripped_copy(t_bin_data *data, char *s)
{
    uint64_t            shdr_size;

    shdr_size = data->core->intel->shdr_size;
    if (!data->copy_size)
        data->copy_size = retrieve_farthest_physical(data->core, data) + 1;
    strip_shdr(data->core, data);
    data->copy_size += (data->core->intel->shdr_size * 2);
    open_extend(data, s);
    data->copy_size -= (data->core->intel->shdr_size * 2);
    ft_memcpy(data->map_copy, data->core->map, retrieve_farthest_physical(data->core, data) + 1);
    add_new_empty_shdr(data, shdr_size);
}
