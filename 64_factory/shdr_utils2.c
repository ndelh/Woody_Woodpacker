/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shdr_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 18:31:51 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/31 18:35:08 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elf_64.h"

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