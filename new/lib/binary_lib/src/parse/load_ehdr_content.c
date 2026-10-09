/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_edhr_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:47:34 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/08 18:47:55 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	load_ehdr_content(t_bin_file *file)
{
	t_file_intel	*intel;
	const t_elf_ops	*elf_caster;
	void			*cursor;

	intel = file->intel;
	cursor = file->map;
	elf_caster = file->elf_caster;
	intel->e_entry = elf_caster->get_entry(cursor);
	intel->e_ehsize = elf_caster->get_ehsize(cursor);
	intel->phdr_offset = elf_caster->get_phdr_offset(cursor);
	intel->shdr_offset = elf_caster->get_shdr_offset(cursor);
	intel->phdr_num = elf_caster->get_phdr_nb(cursor);
	intel->shdr_num = elf_caster->get_shdr_nb(cursor);
	intel->phdr_size = elf_caster->get_phdr_size(cursor);
	intel->shdr_size = elf_caster->get_shdr_size(cursor);
	intel->shstrtab_index = elf_caster->get_shstrndx(cursor);
}