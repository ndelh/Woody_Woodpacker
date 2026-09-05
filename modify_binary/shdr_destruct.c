/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shdr_destruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 18:16:46 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/02 18:26:20 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"

void	shdr_destruct(t_intel *intel, void *cursor)
{
	unsigned char	*content_cursor;
	uint64_t	content_size;
	uint64_t	content_offset;

	content_cursor = intel->ogn_begin;
	content_offset = intel->elf_caster->get_shoffset(cursor);
	content_size = intel->elf_caster->get_shentsize(cursor);
	content_cursor += content_offset;
	//ft_bzero(content_cursor, content_size); //clean must be cleaner because some array are shared between shdr and phdr
	ft_bzero(cursor, intel->bin_data.phdr_size);
}
