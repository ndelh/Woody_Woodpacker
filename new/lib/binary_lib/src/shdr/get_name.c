/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 03:33:33 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/07 03:38:16 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

char	*get_name(void *cursor, t_bin_file *file)
{
	t_file_intel	*intel;
	uint64_t	string_offset;

	intel = file->intel;
	string_offset = file->elf_caster->get_shname(cursor);
	return (intel->strtab + string_offset);
}
