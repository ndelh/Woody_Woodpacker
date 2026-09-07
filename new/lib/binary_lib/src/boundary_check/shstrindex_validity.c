/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shstrndx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 10:27:19 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/06 10:34:30 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

bool	oob_strtab(t_bin_file *file, t_file_intel *intel)
{
	unsigned char	*cursor;
	uint64_t		strtab_offset;
	uint64_t		strtab_size;

	cursor = (unsigned char *)file->map;
	cursor += intel->shdr_offset;
	cursor += intel->shstrtab_index * intel->shdr_size;
	strtab_offset = file->elf_caster->get_shoffset(cursor);
	strtab_size = file->elf_caster->get_shsize(cursor);
	if (is_struct_oob(file, strtab_offset, 1, strtab_size))
		return (true);
	cursor = (unsigned char *)file->map + strtab_offset;
	if (is_strtab_unvalid(cursor, strtab_size))
		return (true);
	intel->strtab = (char *)cursor;
	intel->strtab_size = strtab_size;
	return (false);

}

void	shstrndx_validity(t_bin_file *file, t_bin_data *data)
{
	t_file_intel	*intel;

	intel = file->intel;
	if (intel->shstrtab_index && intel->shstrtab_index >= intel->shdr_num)
	{
		register_error(data, "dubious shdr index", file);
		return ;
	};
	if (oob_strtab(file, intel))
	{
		register_error(data, "dubious shstr table", file);
		return ;
	}
}