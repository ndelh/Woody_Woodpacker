/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phdr_range_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 08:02:13 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 08:02:23 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	phdr_range_check(t_bin_file *file, void *aux_data, void *cursor)
{
    const t_elf_ops   *elf_caster;
    
    (void)aux_data;
    elf_caster = file->elf_caster;
    if (is_struct_oob(file, elf_caster->get_poffsset(cursor), elf_caster->get_pfilesz(cursor), 1))
        register_error("invalid range in phdr", file);
}