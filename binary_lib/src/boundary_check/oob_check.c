/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oob_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:46:10 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 13:47:04 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

bool	add_overflow(uint64_t a, uint64_t b)
{
	return (UINT64_MAX - a < b);
}

bool	mul_overflow(uint64_t a, uint64_t b)
{
	if (!b)
		return (false);
	return (a > UINT64_MAX / b);
}

bool	is_offset_oob(t_bin_file *intel, uint64_t offset)
{
	return (intel->map_size < offset);
}

bool	is_struct_oob(t_bin_file *intel, uint64_t offset, uint64_t struct_nb, uint64_t struct_size)
{
	uint64_t	total_struct_size;

	if (is_offset_oob(intel, offset))
	{
		ft_perror("oob offset");
		return (true);
	}
	if (mul_overflow(struct_nb, struct_size))
	{
		ft_perror("mul_overflow");
		return (true);
	}
	total_struct_size = struct_nb * struct_size;
	if (add_overflow(total_struct_size, offset))
	{
		ft_perror("add_overflow");
		return (true);
	}
	total_struct_size += offset;
	return (intel->map_size < total_struct_size);
}