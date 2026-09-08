/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stub_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 06:01:09 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/07 06:02:53 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"


void	fs_stub_part(t_bin_data *data, t_bin_file *stub)
{
	void			*cursor;
	const t_elf_ops	*elf_caster;
	t_stub_injector	*injector;
	uint64_t		content_offset;

	elf_caster = stub->elf_caster;
	injector = data->stub_injector;
	cursor = find_shdr_by_name(stub, data, ".text");
	if (cursor == NULL)
	{
		register_error(data, ".text cannot be found in stub", stub);
		return ;
	}
	content_offset = elf_caster->get_shoffset(cursor);
	injector->content_size = elf_caster->get_shsize(cursor);
	injector->content_begin = (unsigned char *)stub->map + content_offset;
	fs_find_canaries(data, injector->content_begin, injector->content_size, data->stub_injector);
}

// void	fs_core_part(t_bin_data *data, t_bin_file *core)
// {
		
// }

void	gather_fs_stub_data(t_bin_data *data)
{

	if (data->stoppage)
		return ;
	fs_stub_part(data, data->stub);
	//fs_core_part(data, data->core);
}
