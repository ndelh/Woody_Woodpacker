/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prerequisite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 11:21:41 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/25 11:26:34 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"



int	is_elf(t_intel *intel)
{
	Elf64_Ehdr	*cursor;
	unsigned char		*ident;

	if (intel->ogn_size < sizeof(Elf32_Ehdr))
	{
		ft_perror("file too short to be an elf file");
		return (1);
	}
	cursor = (Elf64_Ehdr *)intel->ogn_begin;
	ident = cursor->e_ident;
	if (ft_memcmp(ident, ELFMAG, SELFMAG))
	{
		ft_perror("file is not an elf file");
		return(1);
	}
	if (ident[EI_CLASS] && ident[EI_CLASS] > 2)
	{
		ft_perror("file is not type 32 or 64");
		return(1);
	}
	if (ident[EI_CLASS] == ELFCLASS64)
		intel->elf_caster = &ops_64;
	return (0);
}

int	check_edge_case(t_intel *intel)
{
	Elf64_Ehdr	*cursor;
	unsigned char		*ident;

	cursor = (Elf64_Ehdr *)intel->ogn_begin;
	ident = cursor->e_ident;
	if (ident[EI_DATA] != ELFDATA2LSB)
	{
		ft_perror("invalid data encoding, this packer only support litle endian");
		return (1);
	}
	return (0);
}


int	check_prerequisite(t_intel *intel)
{
	if (is_elf(intel))
		return (1);
	if (!check_edge_case(intel))
		return (1);
	return (0);
}
