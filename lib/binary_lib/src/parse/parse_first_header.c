/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_first_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 18:39:16 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 19:11:07 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	first_check(t_bin_data *data, t_bin_file *file)
{
	void		*map;

	map = file->map;
	if (file->map_size < sizeof(Elf32_Ehdr))
	{
		register_error(data, "map too short to be any Elf file", file);
		return ;
	}
	if (is_not_elf(map))
	{
		register_error(data,"not an Elf file", file);
		return ;
	}
	if (is_b_endian(map))
		register_error(data, "only little endian is currently supported", file);
	if (is_version_unvalid(map))
		register_error(data, "invalid Elf version", file);
}

void	check_type(t_bin_data *data, t_bin_file *file)
{
	uint64_t	byte_type;

	byte_type = get_byte_type(file->map);
	if (byte_type != ELFCLASS32 && byte_type != ELFCLASS64)
	{
		register_error(data, "invalid byte type", file);
		return ;
	}
	if (byte_type == ELFCLASS64)
		file->elf_caster = &ops_64;
}

void	parse_first_header(t_bin_data *data, t_bin_file *file)
{	
	first_check(data, file);
	if (data->stoppage)
		return ;
	check_type(data, file);
}

void	first_parse(t_bin_data *data)
{
	parse_first_header(data, data->core);
	if (data->stub && !(data->stoppage))
	{
		parse_first_header(data, data->stub);
		if (data->stub->elf_caster != data->core->elf_caster && !(data->stoppage))
			register_error(data, "conflict between stub type and core file type", NULL);
	}
}