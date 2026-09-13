/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_basic_stub_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 08:10:35 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/09 08:12:11 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	change_pt_note(t_bin_data *data)
{
	void		*pt_note_hdr;

	pt_note_hdr = find_first_phdr_of_type(data->core, data, PT_NOTE);
	if (!pt_note_hdr)
	{
		register_error(data, "pt note not found", data->core);
		return ;
	}
	craft_stub_phdr(data, pt_note_hdr);
	
}

void	inject_stub(t_bin_data *data)
{
	unsigned char	*cursor;
	uint64_t		*stub_inject;

	cursor = (unsigned char *)data->map_copy + data->stub_injector->av_core_offset;
	print_all_phdr_range(data->core, data);
	stub_inject = (uint64_t *)data->stub_injector->current_placeholder;
	*stub_inject = data->core->intel->e_entry;
	ft_memcpy(cursor, data->stub_injector->content_begin, data->stub_injector->content_size);
	data->core->elf_caster->set_entry(data->map_copy, data->stub_injector->av_addr);
	printf("expected entrypoint %lx\n", data->stub_injector->av_addr);
	printf("changed entrypoint to %lx\n", data->core->elf_caster->get_entry(data->map_copy));
}

void	fs_basic_stub_copy(t_bin_data *data, char *new_doc)
{
	gather_fs_stub_data(data);
	change_pt_note(data);
	data->copy_size = data->stub_injector->av_core_offset + data->stub_injector->content_size + 1;
	stripped_copy(data, new_doc);
	inject_stub(data);
}
