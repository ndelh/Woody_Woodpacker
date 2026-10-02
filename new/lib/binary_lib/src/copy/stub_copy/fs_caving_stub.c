/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caving_stub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 13:09:02 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/13 19:44:27 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	caving_process(t_bin_data *data, char *s, void *phdr_to_cave, uint64_t bss_size)
{
	unsigned char	*cpy_point;
	uint64_t		oep;
	uint64_t		new_ep;
	const t_elf_ops	*elf_caster;

	elf_caster = data->core->elf_caster;
	open_extend(data, s);
	cpy_point = (unsigned char *)data->core->map + elf_caster->get_poffsset(phdr_to_cave) + elf_caster->get_pfilesz(phdr_to_cave) + bss_size;
	oep = elf_caster->get_entry(data->core->map);
	new_ep = elf_caster->get_pvaddr(phdr_to_cave) + elf_caster->get_pmemsz(phdr_to_cave) + bss_size;
	elf_caster->set_entry(data->core->map, new_ep); //setting entry to the end of old content
	compute_ep_offset(data->core, data, oep, new_ep);
	elf_caster->set_pmemsz(phdr_to_cave, elf_caster->get_pmemsz(phdr_to_cave) + data->stub_injector->content_size); // actualizing pmesz
	elf_caster->set_pfilesz(phdr_to_cave, elf_caster->get_pfilesz(phdr_to_cave) + data->stub_injector->content_size); //actualiszing pfilesz
	// printf("ancient oep and current placeholder not hex: %lu, hex: %lx\n", oep, *place_holder);
	// printf("current eop not hex: %lu, hex: %lx", elf_caster->get_entry(data->core->map), elf_caster->get_entry(data->core->map));
	ft_memcpy(cpy_point, data->stub_injector->content_begin, data->stub_injector->content_size);
}

bool    fs_caving_stub(t_bin_data *data, char *s)
{
	void	*phdr_to_cave;
	uint64_t	bss_size;

	(void)s;
	gather_fs_stub_data(data);	
	phdr_to_cave = find_cave(data->core, data);
	if (!phdr_to_cave)
		return 1;
	bss_size =  find_bss_size(data->core->elf_caster, phdr_to_cave);
	data->copy_size = data->core->map_size;
	caving_process(data, s, phdr_to_cave, bss_size);
	ft_memcpy(data->map_copy, data->core->map, data->copy_size);
	return (0);
}	
