/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   universal_getter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 18:46:36 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 19:01:17 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

bool	is_not_elf(const void *map)
{
	return (ft_memcmp(map, ELFMAG, SELFMAG));
}

uint64_t	get_byte_type(const void *map)
{
	unsigned char	*s;

	s = (unsigned char *)map;
	return (s[EI_CLASS]);
}

bool	is_b_endian(const void *map)
{
	unsigned char	*s;
	
	s = (unsigned char *)map;
	return (s[EI_DATA] != ELFDATA2LSB);
}

bool	is_version_unvalid(const void *map)
{
	unsigned char	*s;

	s = (unsigned char *)map;
	return (s[EI_VERSION] != EV_CURRENT);
}
