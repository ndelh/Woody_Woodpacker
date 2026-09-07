/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_shdr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 22:37:11 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/06 22:42:36 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

typedef struct	s_legal_erase
{
	uint64_t	content_begin;
	uint64_t	content_end;
	bool		shared;
}	t_legal_erase;


void	is_shared_with_phdr(t_bin_file *file, t_bin_data *data, void *aux_data, void *cursor)
{
		t_legal_erase	*legality;
		uint64_t	phdr_content_begin;
		uint64_t	phdr_content_end;

		(void)data;
		legality = (t_legal_erase *)aux_data;
		if (legality->shared || file->elf_caster->get_ptype(cursor) != PT_LOAD)
			return ;
		phdr_content_begin = file->elf_caster->get_poffsset(cursor);
		phdr_content_end = phdr_content_begin + file->elf_caster->get_pfilesz(cursor) - 1;
		if (phdr_content_end < legality->content_begin || legality->content_end < phdr_content_begin)
			return ;
		legality->shared = true;
}

void	destroy_current_shdr(t_bin_file *file, t_bin_data *data, void *aux_data, void *cursor)
{

	t_legal_erase	legal_action;
	uint64_t		content_size;
	unsigned char	*erase_start;

	(void)aux_data;
	legal_action.content_begin = file->elf_caster->get_shoffset(cursor);
	content_size = file->elf_caster->get_shsize(cursor);
	if (content_size && file->elf_caster->get_shtype(cursor) != SHT_NOBITS)
	{
		legal_action.content_end = legal_action.content_begin + content_size - 1;
		legal_action.shared = 0;
		iterate_phdr(file, data, &legal_action, is_shared_with_phdr);
		if (!(legal_action.shared))
		{
			erase_start = (unsigned char *)file->map + legal_action.content_begin;
			ft_bzero(erase_start, content_size);
		}
	}
	ft_bzero(cursor, file->intel->shdr_size);
}

void	strip_shdr(t_bin_file *file, t_bin_data *data)
{
	unsigned char	*cursor;
	const t_elf_ops		*elf_caster;
	
	if (data->stoppage)
		return ;
	cursor = (unsigned char *)file->map;
	elf_caster = file->elf_caster;
	iterate_shdr(file, data, NULL, destroy_current_shdr);
	elf_caster->set_shdr_offset(cursor, 0);
	elf_caster->set_shdr_nb(cursor, 0);
	elf_caster->set_shstrndx(cursor, 0);
}
