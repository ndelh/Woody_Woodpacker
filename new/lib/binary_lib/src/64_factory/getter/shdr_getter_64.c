/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shdr_getter_64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:30:54 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 12:31:23 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../elf_64.h"

uint64_t	get_sh_name_64(const void *cursor)
{
	return (((Elf64_Shdr *)cursor)->sh_name);
}

uint64_t	get_sh_type_64(const void *cursor)
{
	return (((Elf64_Shdr *)cursor)->sh_type);
}

uint64_t	get_sh_flags_64(const void *cursor)
{
	return (((Elf64_Shdr *)cursor)->sh_flags);
}

uint64_t	get_sh_addr_64(const void *cursor)
{
	return (((Elf64_Shdr *)cursor)->sh_addr);
}

uint64_t	get_sh_offset_64(const void *cursor)
{
	return (((Elf64_Shdr *)cursor)->sh_offset);
}

uint64_t	get_sh_size_64(const void *cursor)
{
	return (((Elf64_Shdr *)cursor)->sh_size);
}

uint64_t	get_sh_link_64(const void *cursor)
{
	return (((Elf64_Shdr *)cursor)->sh_link);
}

uint64_t	get_sh_info_64(const void *cursor)
{
	return (((Elf64_Shdr *)cursor)->sh_info);
}

uint64_t	get_sh_addralign_64(const void *cursor)
{
	return (((Elf64_Shdr *)cursor)->sh_addralign);
}

uint64_t	get_sh_entsize_64(const void *cursor)
{
	return (((Elf64_Shdr *)cursor)->sh_entsize);
}
