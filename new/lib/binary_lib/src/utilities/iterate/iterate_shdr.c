/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_shdr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 20:48:10 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 20:48:20 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	iterate_shdr(t_bin_file *file, t_bin_data *data, void(*func)(t_bin_file *file, t_bin_data *data, void *))
{
	unsigned char	*cursor;
	t_file_intel	*intel;
	uint64_t	shdr_offset;
	uint64_t	shdr_nb;
	uint64_t		shdr_size;
	
	intel = file->intel;
	cursor = (unsigned char *)file->map;
	shdr_offset = intel->shdr_offset;
	shdr_nb = intel->shdr_num;
	shdr_size = intel->shdr_size; 
	cursor += shdr_offset;
	while (shdr_nb--)
	{
		if (func)
			func(file, data, cursor);
		cursor += shdr_size;
	}
}