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

void	destroy_current_shdr(t_bin_file *file, t_bin_data *data, void *cursor)
{
	//erase_content;
	ft_bzero(cursor, file->intel->shdr_size);
	(void)data;
}

void	strip_shdr(t_bin_file *file, t_bin_data *data)
{
	unsigned char	*cursor;
	const t_elf_ops		*elf_caster;
	
	cursor = (unsigned char *)file->map;
	elf_caster = file->elf_caster;
	iterate_shdr(file, data, destroy_current_shdr);
	elf_caster->set_phdr_offset(cursor, 0);
	elf_caster->set_phdr_nb(cursor, 0);
	elf_caster->set_shstrndx(cursor, 0);
}
