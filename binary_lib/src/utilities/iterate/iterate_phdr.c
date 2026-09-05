/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_phdr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:48:44 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 20:47:02 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	iterate_phdr(t_bin_file *file, t_bin_data *data, void(*func)(t_bin_file *file, t_bin_data *data, void *))
{
	unsigned char	*cursor;
	t_file_intel	*intel;
	uint64_t	phdr_offset;
	uint64_t	phdr_nb;
	uint64_t		phdr_size;
	
	intel = file->intel;
	cursor = (unsigned char *)file->map;
	phdr_offset = intel->phdr_offset;
	phdr_nb = intel->phdr_num;
	phdr_size = intel->phdr_size; 
	cursor += phdr_offset;
	while (phdr_nb--)
	{
		if (func)
			func(file, data, cursor);
		cursor += phdr_size;
	}
}

