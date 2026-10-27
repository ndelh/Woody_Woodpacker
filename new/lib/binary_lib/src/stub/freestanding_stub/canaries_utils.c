/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:28:01 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/27 14:28:02 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	canary_loop_64(void *cursor, uint64_t size, uint64_t *canaries_nb)
{
	uint64_t	canary_value;
	
	canary_value = CANARY_VALUE_64;
	while (size >= 8 && (!ft_memcmp(cursor, &canary_value, sizeof(uint64_t))))
	{
		cursor += 8;
		--(*canaries_nb);
		size -= 8;
	}
}

void	fs_find_canaries_64(t_bin_file *stub, void *cursor, uint64_t size)
{
	uint64_t		canaries_nb;
	uint64_t		canary_value;
	
	canary_value = CANARY_VALUE_64;
	canaries_nb = CANARY_NB_64;
	while (size >= 8)
	{	
		if (!ft_memcmp(cursor, &canary_value, sizeof(uint64_t)))
		{
			stub->stub_data->canaries_begin = cursor;
			canary_loop_64(cursor, size, &canaries_nb);
			break ;
		}
		++cursor;
		--size;
	}
	if (canaries_nb)
		register_error("too few canaries in stub", stub);
}

void	canary_loop_32(void *cursor, uint64_t size, uint64_t *canaries_nb)
{
	uint32_t	canary_value;
	
	canary_value = CANARY_VALUE_32;
	while (size >= 4 && (!ft_memcmp(cursor, &canary_value, sizeof(uint32_t))))
	{
		cursor += 4;
		--(*canaries_nb);
		size -= 4;
	}
}

void	fs_find_canaries_32(t_bin_file *stub, void *cursor, uint64_t size)
{
	uint64_t		canaries_nb;
	uint32_t		canary_value;
	
	canary_value = CANARY_VALUE_32;
	canaries_nb = CANARY_NB_32;
	while (size >= 4)
	{	
		if (!ft_memcmp(cursor, &canary_value, sizeof(uint32_t)))
		{
			stub->stub_data->canaries_begin = cursor;
			canary_loop_32(cursor, size, &canaries_nb);
			break ;
		}
		++cursor;
		--size;
	}
	if (canaries_nb)
		register_error("too few canaries in stub", stub);
	printf("canaries: %lu\n", canaries_nb);
}
