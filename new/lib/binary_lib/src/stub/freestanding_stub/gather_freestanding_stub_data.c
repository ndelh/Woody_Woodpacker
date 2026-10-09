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

void	canary_loop(void *cursor, uint64_t size, uint64_t *canaries_nb)
{
	uint64_t	canary_value;
	
	canary_value = CANARY_VALUE;
	while (size >= 8 && (!ft_memcmp((uint64_t *)cursor, &canary_value, sizeof(uint64_t))))
	{
		cursor += 8;
		printf("canaries adress: %p\n", cursor);
		--(*canaries_nb);
		size -= 8;
	}
}

void	fs_find_canaries(t_bin_file *stub, void *cursor, uint64_t size)
{
	uint64_t		canaries_nb;
	uint64_t		canary_value;
	
	canary_value = CANARY_VALUE;
	canaries_nb = CANARY_NB;
	while (size >= 8)
	{	
		if (!ft_memcmp(cursor, &canary_value, sizeof(uint64_t)))
		{
			stub->stub_data->canaries_begin= cursor;
			canary_loop(cursor, size, &canaries_nb);
			break ;
		}
		++cursor;
		--size;
	}
	if (canaries_nb)
		register_error("too few canaries in stub", stub);
	else
		printf("canary_found\n");
}


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
	fs_find_canaries(stub, data->content_begin, data->content_size);
}

// void	fs_core_part(t_bin_data *data, t_bin_file *core)
// {
// 	uint64_t	next_available_faddr;

// 	data->stub_injector->av_addr = get_next_available_vaddr(core, data);
// 	next_available_faddr = retrieve_farthest_physical(core, data) + 1;
// 	next_available_faddr = find_next_aligned_value(next_available_faddr, PAGESIZE);
// 	data->stub_injector->av_core_offset = next_available_faddr;
// }

void	gather_fs_stub_data(t_bin_file *file)
{
	file->stub_data = malloc(sizeof(t_stub_data));
	if (!(file->stub_data))
		register_error("failed to allocate stub data struct", file);
	file_launcher(file, fetch_stub_data);
}
