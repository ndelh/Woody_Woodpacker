/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_shdr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 07:31:12 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 07:31:35 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	iter_shdr(t_bin_file *file, void *aux_data, void(*func)(t_bin_file *file, void *, void *))
{
	unsigned char	*cursor;
	t_file_intel	*intel;
	uint64_t	shdr_offset;
	uint64_t	shdr_nb;
	uint64_t		shdr_size;
	
	intel = file->intel;
	cursor = (unsigned char *)file->map;
	shdr_offset = intel->shdr_offset;
	cursor += shdr_offset;
	shdr_nb = intel->shdr_num;
	shdr_size = intel->shdr_size; 
	while (shdr_nb--)
	{
		if (func)
			func(file, aux_data, cursor);
		cursor += shdr_size;
	}
}