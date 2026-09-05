/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stub_phdr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 10:48:05 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/03 10:57:06 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elf_64.h"

void	write_stub_phdr_64(t_intel *intel, void *cursor)
{
	Elf64_Phdr		*stub_p;
	t_stub_loader	*stub_loader;

	stub_p = (Elf64_Phdr *)cursor;
	stub_loader = &intel->stub_loader;
	stub_p->p_type = PT_LOAD;
	stub_p->p_flags = PF_X | PF_R;
	stub_p->p_offset =  stub_loader->stub_content_offset;
	stub_p->p_vaddr = stub_loader->av_addr;
	stub_p->p_paddr = stub_loader->av_addr;
	stub_p->p_filesz = stub_loader->content_size;
	stub_p->p_memsz = stub_loader->content_size;
	stub_p->p_align = 0x1000;
	intel->elf_caster->set_phdr_nb(cursor, intel->bin_data.phdr_num + 1);
	intel->elf_caster->set_entry(cursor, stub_loader->av_addr);
}	
