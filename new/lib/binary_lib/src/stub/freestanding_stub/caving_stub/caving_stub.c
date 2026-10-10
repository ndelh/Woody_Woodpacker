/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caving_stub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 14:20:25 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 14:22:03 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	caving_process(t_bin_file *target, t_bin_file *stub, void *phdr_to_cave, uint64_t bss_size)
{
	unsigned char	*cpy_point;
	uint64_t		oep;
	uint64_t		new_ep;
	const t_elf_ops	*elf_caster;

	elf_caster = target->elf_caster;
	cpy_point = (unsigned char *)target->map + elf_caster->get_poffsset(phdr_to_cave) + elf_caster->get_pfilesz(phdr_to_cave) + bss_size;
	oep = elf_caster->get_entry(target->map);
	new_ep = elf_caster->get_pvaddr(phdr_to_cave) + elf_caster->get_pmemsz(phdr_to_cave) + bss_size;
	elf_caster->set_entry(target->map, new_ep); //setting entry to the end of old content
	compute_ep_offset(target, stub, oep, new_ep);
	elf_caster->set_pmemsz(phdr_to_cave, elf_caster->get_pmemsz(phdr_to_cave) + stub->stub_data->content_size); // actualizing pmesz
	elf_caster->set_pfilesz(phdr_to_cave, elf_caster->get_pfilesz(phdr_to_cave) + stub->stub_data->content_size); //actualiszing pfilesz
	ft_memcpy(cpy_point, stub->stub_data->content_begin, stub->stub_data->content_size);
}

bool	freestanding_caving_stub(t_bin_file *target, t_bin_file *stub, bool cypher)
{
	void	*phdr_to_cave;
	uint64_t	bss_size;

	phdr_to_cave = find_cave(target, stub->stub_data->content_size);
	if (!phdr_to_cave)
		return 1;
	bss_size =  find_bss_size(target->elf_caster, phdr_to_cave);
	if (cypher == true)
		cypher_pt_load(target, stub);
	caving_process(target, stub, phdr_to_cave, bss_size);
	return 0;
}