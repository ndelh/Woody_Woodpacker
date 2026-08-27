/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:48:44 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/27 16:27:11 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"


void	iterate_phdr(t_intel *intel, void(*func)(t_intel *, void *))
{
	unsigned char	*cursor;
	uint64_t	phdr_offset;
	uint16_t	phdr_nb;
	uint8_t		phdr_size;
	
	cursor = (unsigned char *)intel->ogn_begin;
	phdr_offset = intel->bin_data.phdr_offset;
	phdr_nb = intel->bin_data.phdr_num;
	phdr_size = intel->bin_data.phdr_size; 
	cursor += phdr_offset;
	while (phdr_nb--)
	{
		if (func)
			func(intel, cursor);
		cursor += phdr_size;
	}
}

void	iterate_shdr(t_intel *intel, void(*func)(t_intel *, void *))
{
	unsigned char	*cursor;
	uint64_t	shdr_offset;
	uint16_t	shdr_nb;
	uint8_t		shdr_size;
	
	cursor = (unsigned char *)intel->ogn_begin;
	shdr_offset = intel->bin_data.shdr_offset;
	shdr_nb = intel->bin_data.shdr_num;
	shdr_size = intel->bin_data.shdr_size; 
	cursor += shdr_offset;
	while (shdr_nb--)
	{
		if (func)
			func(intel, cursor);
		cursor += shdr_size;
	}
}
