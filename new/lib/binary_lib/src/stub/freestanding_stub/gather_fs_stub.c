/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_fs_stub_64.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 06:01:09 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/26 16:58:13 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"


void	fetch_stub_data(t_bin_file *stub)
{
	void			*cursor;
	const t_elf_ops	*elf_caster;
	uint64_t		content_offset;
	t_stub_data		*data;

	ft_bzero(stub->stub_data, sizeof(t_stub_data));
	data = stub->stub_data;
	elf_caster = stub->elf_caster;
	cursor = find_first_shdr_of_name(stub, ".text");
	if (cursor == NULL)
	{
		register_error(".text cannot be found in stub", stub);
		return ;
	}
	content_offset = elf_caster->get_shoffset(cursor);
	data->content_size = elf_caster->get_shsize(cursor);
	data->content_begin = (unsigned char *)stub->map + content_offset;
	if (get_byte_type(stub->map) == ELFCLASS64) 
		fs_find_canaries_64(stub, data->content_begin, data->content_size);
	else
		fs_find_canaries_32(stub, data->content_begin, data->content_size);
}

void	gather_fs_stub_data(t_bin_file *file)
{
	file->stub_data = malloc(sizeof(t_stub_data));
	if (!(file->stub_data))
		register_error("failed to allocate stub data struct", file);
	file_launcher(file, fetch_stub_data);
}
