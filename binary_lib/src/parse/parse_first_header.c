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

uint64_t	first_check(t_bin_data *data, t_bin_file *file)
{
	void		*map;
	uint64_t	class;

	map = file->map;
	if (file->map_size < sizeof(Elf32_Ehdr))
		ft_end_msg(data, 2, "file too short to be an Elf file");
	if (is_not_elf(map))
		ft_end_msg(data, 2,"not an Elf file");
	if (is_b_endian(map))
		ft_end_msg(data, 2, "only little endian is currently supported");
	if (is_version_unvalid(map))
		ft_end_msg(data, 2, "invalid Elf version");
	class = get_byte_type(map);
	if (class == ELFCLASS64 && file->map_size < sizeof(Elf64_Ehdr))
			ft_end_msg(data, 2, "file too short to be an Elf64 file");
	return (class);
}

void	parse_first_header(t_bin_data *data)
{
	uint64_t	core_class;
	
	core_class = first_check(data, data->core);
	if (core_class == ELFCLASS64)
		data->elf_caster = &ops_64;
	else
		ft_end(data, 0);
	if (!(data->stub))
		return;
	if (first_check(data, data->stub) != core_class)
		ft_end_msg(data, STDIN_FILENO, "incapabilities between stub type and binary_type");
}