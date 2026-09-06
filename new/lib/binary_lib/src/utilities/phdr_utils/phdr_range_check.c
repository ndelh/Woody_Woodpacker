/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phdr_value_range_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 20:58:55 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 21:05:32 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	phdr_range_check(t_bin_file *file, t_bin_data *data, void *cursor)
{
    const t_elf_ops   *elf_caster;

    elf_caster = file->elf_caster;
    if (is_struct_oob(file, elf_caster->get_poffsset(cursor), elf_caster->get_pfilesz(cursor), 1))
        ft_end_msg(data, STDERR_FILENO, "invalid range in phdr");
}