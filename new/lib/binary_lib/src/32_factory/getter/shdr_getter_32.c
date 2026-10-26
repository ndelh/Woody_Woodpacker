/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shdr_getter_32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:30:54 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 12:31:23 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../elf_32.h"

uint64_t	get_sh_name_32(const void *cursor)
{
	return (((Elf32_Shdr *)cursor)->sh_name);
}

uint64_t	get_sh_type_32(const void *cursor)
{
	return (((Elf32_Shdr *)cursor)->sh_type);
}

uint64_t	get_sh_flags_32(const void *cursor)
{
	return (((Elf32_Shdr *)cursor)->sh_flags);
}

uint64_t	get_sh_addr_32(const void *cursor)
{
	return (((Elf32_Shdr *)cursor)->sh_addr);
}

uint64_t	get_sh_offset_32(const void *cursor)
{
	return (((Elf32_Shdr *)cursor)->sh_offset);
}

uint64_t	get_sh_size_32(const void *cursor)
{
	return (((Elf32_Shdr *)cursor)->sh_size);
}

uint64_t	get_sh_link_32(const void *cursor)
{
	return (((Elf32_Shdr *)cursor)->sh_link);
}

uint64_t	get_sh_info_32(const void *cursor)
{
	return (((Elf32_Shdr *)cursor)->sh_info);
}

uint64_t	get_sh_addralign_32(const void *cursor)
{
	return (((Elf32_Shdr *)cursor)->sh_addralign);
}

uint64_t	get_sh_entsize_32(const void *cursor)
{
	return (((Elf32_Shdr *)cursor)->sh_entsize);
}
