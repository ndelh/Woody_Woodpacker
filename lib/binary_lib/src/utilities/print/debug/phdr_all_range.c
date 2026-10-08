/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phdr_all_range.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 01:18:55 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/11 01:21:40 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	p_all_p_range(void *cursor, const t_elf_ops *elf_caster)
{
	static int	nb;
	uint64_t	phdr_offset;
	uint64_t	phdr_pfilz;
	uint64_t	phdr_content_end;

	phdr_offset = elf_caster->get_poffsset(cursor);
	phdr_pfilz = elf_caster->get_pfilesz(cursor);
	if (!phdr_pfilz)
		phdr_content_end = phdr_offset;
	else
		phdr_content_end = phdr_offset + phdr_pfilz - 1;
	printf(COLOR_BLUE "for phdr nb :%i\n" COLOR_RESET, nb++);
	printf(COLOR_GREEN "phdr offset %lu, " COLOR_YELLOW "phdr size on file %lu\n" COLOR_RESET, phdr_offset, phdr_pfilz);
	printf(COLOR_RED COLOR_BOLD "phdr file range [%lu - %lu]\n" COLOR_RESET, phdr_offset, phdr_content_end);
	CR_DEFAULT;
}

void	print_all_phdr_range(t_bin_file *file, t_bin_data *data)
{
	unsigned char	*cursor;
	uint64_t	iteration;

	cursor = (unsigned char *)file->map;
	cursor += file->intel->phdr_offset;
	iteration = file->intel->phdr_num;
	while (iteration--)
	{
		p_all_p_range(cursor, file->elf_caster);
		cursor += file->intel->phdr_size;
	}
	if (data->stub_injector->av_core_offset)
	{
		CR_DEFAULT;
		printf(COLOR_GREEN COLOR_BOLD "data stub content calculated range [%lu-%lu]\n" COLOR_RESET, data->stub_injector->av_core_offset, data->stub_injector->av_core_offset + data->stub_injector->content_size - 1);
	}
	CR_DEFAULT;
}
