/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_ehdr_intel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 12:06:34 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/27 12:15:08 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../woody_woodpacker.h"

void	fetch_basics(t_intel *intel)
{
	const t_elf_ops	*use;
	t_elf_navigator	*nav;
	void			*map;

	use = intel->elf_caster;
	nav = &intel->bin_data;
	map = intel->ogn_begin;

	nav->entry = use->get_entry(map);
	nav->phdr_offset = use->get_phdr_offset(map);
	nav->phdr_num = use->get_phdr_nb(map);
	nav->phdr_size = use->get_phdr_size(map);
	nav->shdr_offset = use->get_shdr_offset(map);
	nav->shdr_num = use->get_shdr_nb(map);
	nav->shdr_size = use->get_shdr_size(map);
	nav->shstrndx = use->get_shstrndx(map);
}

void	check_basics(t_intel *intel)
{
	const t_elf_navigator	*nav;
	uint64_t				limit;

	nav = &intel->bin_data;
	limit = intel->ogn_size;

	if (is_struct_oob(intel, nav->phdr_offset, nav->phdr_num, nav->phdr_size))
		error_end("dubious phdr section", 1, intel);
	if (is_struct_oob(intel, nav->shdr_offset, nav->shdr_num, nav->shdr_size))
		error_end("dubious shdr section", 1, intel);
	if (nav->shstrndx && nav->shstrndx >= nav->shdr_num)
		error_end("fallacious shstrndx", 1, intel);
}

void	gather_ehdr(t_intel *intel)
{
	fetch_basics(intel);
	check_basics(intel);
	iterate_phdr(intel, NULL);
	iterate_shdr(intel, NULL);
}
