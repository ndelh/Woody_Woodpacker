/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_canaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 07:45:53 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/07 07:46:04 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	canary_loop(void *cursor, uint64_t size, uint64_t *canaries_nb)
{
	uint64_t	canary_value;
	
	canary_value = CANARY_VALUE;
	while (size >= 8 && (!ft_memcmp((uint64_t *)cursor, &canary_value, sizeof(uint64_t))))
	{
		cursor += 8;
		--(*canaries_nb);
		size -= 8;
	}
}
void	fs_find_canaries(t_bin_data *data, void *cursor, uint64_t size, t_stub_injector *injector)
{
	void			*first_canary;
	uint64_t		canaries_nb;
	uint64_t		canary_value;
	
	canary_value = CANARY_VALUE;
	canaries_nb = CANARY_NB;
	first_canary = NULL;
	while (size >= 8)
	{	
		if (!ft_memcmp(cursor, &canary_value, sizeof(uint64_t)))
		{
			first_canary = cursor;
			canary_loop(cursor, size, &canaries_nb);
			break ;
		}
		++cursor;
		--size;
	}
	if (canaries_nb)
		register_error(data, "too few canaries in stub", data->stub);
	injector->current_placeholder = first_canary;
}