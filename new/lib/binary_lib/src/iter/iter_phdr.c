/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_phdr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 07:31:44 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 07:31:59 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	iter_phdr(t_bin_file *file, void *aux_data, void(*func)(t_bin_file *file, void *, void *))
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
			func(file, aux_data, cursor);
		cursor += phdr_size;
	}
}