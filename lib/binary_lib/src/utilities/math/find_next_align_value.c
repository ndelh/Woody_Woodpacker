/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_align_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 04:12:03 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/09 04:13:04 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

uint64_t	find_next_aligned_value(uint64_t value, uint64_t align)
{
    if (!is_power_2(align))
        return (0);
    return (value + (align - 1)) & ~(align - 1);
}
