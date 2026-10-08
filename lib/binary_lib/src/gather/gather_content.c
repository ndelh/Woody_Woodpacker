/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 19:43:11 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 19:45:52 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	load_content(t_bin_file *file)
{
	t_file_intel	*intel;
	const t_elf_ops	*elf_caster;
	void			*cursor;

	intel = file->intel;
	cursor = file->map;
	elf_caster = file->elf_caster;
	intel->e_entry = elf_caster->get_entry(cursor);
	intel->phdr_offset = elf_caster->get_phdr_offset(cursor);
	intel->shdr_offset = elf_caster->get_shdr_offset(cursor);
	intel->phdr_num = elf_caster->get_phdr_nb(cursor);
	intel->shdr_num = elf_caster->get_shdr_nb(cursor);
	intel->phdr_size = elf_caster->get_phdr_size(cursor);
	intel->shdr_size = elf_caster->get_shdr_size(cursor);
	intel->shstrtab_index = elf_caster->get_shstrndx(cursor);
}

void	gather_ehdr_content(t_bin_data *data)
{
	load_content(data->core);
	if ((data->stub))
		load_content(data->stub);
}
