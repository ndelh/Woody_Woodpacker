/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shdr_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:50:13 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/31 18:29:23 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elf_64.h"

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
