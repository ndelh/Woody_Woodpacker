/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shdr_wrapped_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 08:05:38 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/01 08:15:10 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"

bool	check_strtab(t_intel *intel, uint64_t offset, uint64_t len)
{
	if (is_struct_oob(intel, offset, len, 1))
	{
		ft_perror("dubious shsstr");
		return(1);
	}
	return (0);
}

bool	retrieve_strtab(t_intel *intel)
{
	unsigned char 	*cursor;
	t_elf_navigator		*nav;
	const t_elf_ops		*elf_caster;
	uint64_t		str_tab_offset;
	uint64_t		str_tab_len;

	elf_caster = intel->elf_caster;
	nav = &intel->bin_data;
	cursor = (unsigned char *)intel->ogn_begin;
	cursor += nav->shdr_offset;
	cursor += (nav->shstrndx * nav->shdr_size);
	str_tab_offset = elf_caster->get_shoffset(cursor);
	str_tab_len = elf_caster->get_shsize(cursor);
	if (check_strtab(intel, str_tab_offset, str_tab_len))
		return (1);
	nav->strtab_len = str_tab_len;
	nav->strtab_begin = (unsigned char *)intel->ogn_begin;
	nav->strtab_begin += str_tab_offset;
	return (0);
}

unsigned char	*retrieve_shdr_name(t_intel *intel, void *cursor)
{
	uint64_t		name_offset;
	t_elf_navigator	*nav;

	nav = &intel->bin_data;
	name_offset = intel->elf_caster->get_shname(cursor);
	if (name_offset > nav->strtab_len)
		return (NULL);
	return (nav->strtab_begin + name_offset);
}
