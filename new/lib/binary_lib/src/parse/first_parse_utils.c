/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parse_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:22:38 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/08 18:22:52 by ndelhota         ###   ########.fr       */
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