/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shdr_range_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 09:44:16 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/06 09:44:47 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	shdr_range_check(t_bin_file *file, t_bin_data *data, void *aux_data, void *cursor)
{
    const t_elf_ops   *elf_caster;

    (void)aux_data;
    elf_caster = file->elf_caster;
    if (is_struct_oob(file, elf_caster->get_shoffset(cursor) , elf_caster->get_shentsize(cursor), 1))
        register_error(data, "invalid shdr content range", file);
    if (elf_caster->get_shname(cursor) > file->intel->strtab_size)
        register_error(data, "invalid name index", file);
}