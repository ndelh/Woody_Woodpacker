/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   craft_stub_phdr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 09:19:19 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/09 09:19:32 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void    craft_stub_phdr(t_bin_data *data, void *phdr)
{
    const t_elf_ops   *elf_caster;

    elf_caster = data->core->elf_caster;
    elf_caster->set_ptype(phdr, PT_LOAD);
    elf_caster->set_pvaddr(phdr, data->stub_injector->av_addr);
    elf_caster->set_ppaddr(phdr, data->stub_injector->av_addr);
    elf_caster->set_pfilesz(phdr, data->stub_injector->content_size);
    elf_caster->set_pmemsz(phdr, data->stub_injector->content_size);
    elf_caster->set_palign(phdr, PAGESIZE);
}