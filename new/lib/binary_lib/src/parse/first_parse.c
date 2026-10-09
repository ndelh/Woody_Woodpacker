/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 18:39:16 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/08 18:06:42 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	first_check(t_bin_file *file)
{
	void		*map;

	map = file->map;
	if (file->map_size < sizeof(Elf32_Ehdr))
	{
		register_error("map too short to be any Elf file", file);
		return ;
	}
	if (is_not_elf(map))
	{
		register_error("not an Elf file", file);
		return ;
	}
	if (is_b_endian(map))
		register_error("only little endian is currently supported", file);
	if (is_version_unvalid(map))
		register_error("invalid Elf version", file);
}

void	check_type(t_bin_file *file)
{
	uint64_t	byte_type;

	byte_type = get_byte_type(file->map);
	if (byte_type != ELFCLASS32 && byte_type != ELFCLASS64)
	{
		register_error("invalid byte type", file);
		return ;
	}
	if (byte_type == ELFCLASS64)
		file->elf_caster = &ops_64;
}

void	first_parse(t_bin_file *file)
{	
	first_check(file);
	file_launcher(file, check_type);
}
