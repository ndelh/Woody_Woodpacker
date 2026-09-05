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

void	load_content(t_bin_file *file, const t_elf_ops *elf_caster)
{
	t_file_intel	*intel;
	void			*cursor;

	intel = file->intel;
	cursor = file->map;
	intel->e_entry = elf_caster->get_entry(cursor);
	intel->phdr_offset = elf_caster->get_phdr_offset(cursor);
	intel->shdr_offset = elf_caster->get_shdr_offset(cursor);
	intel->phdr_num = elf_caster->get_phdr_nb(cursor);
	intel->shdr_num = elf_caster->get_shdr_nb(cursor);
	intel->phdr_size = elf_caster->get_phdr_size(cursor);
	intel->shdr_size = elf_caster->get_shdr_size(cursor);
}

void	gather_content(t_bin_data *data)
{
	load_content(data->core, data->elf_caster);
	if (!(data->stub))
		return ;
	load_content(data->stub, data->elf_caster);
}
