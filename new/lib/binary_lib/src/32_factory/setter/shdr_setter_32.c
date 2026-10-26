/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shdr_setter_32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 19:25:27 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/10 19:25:37 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	set_sh_name_32(void *ogn_map, uint64_t new_value)
{
	((Elf32_Shdr *)ogn_map)->sh_name = new_value;
}

void	set_sh_type_32(void *ogn_map, uint64_t new_value)
{
	((Elf32_Shdr *)ogn_map)->sh_type = new_value;
}

void	set_sh_flags_32(void *ogn_map, uint64_t new_value)
{
	((Elf32_Shdr *)ogn_map)->sh_flags = new_value;
}

void	set_sh_addr_32(void *ogn_map, uint64_t new_value)
{
	((Elf32_Shdr *)ogn_map)->sh_addr = new_value;
}

void	set_sh_offset_32(void *ogn_map, uint64_t new_value)
{
	((Elf32_Shdr *)ogn_map)->sh_offset = new_value;
}

void	set_sh_size_32(void *ogn_map, uint64_t new_value)
{
	((Elf32_Shdr *)ogn_map)->sh_size = new_value;
}

void	set_sh_link_32(void *ogn_map, uint64_t new_value)
{
	((Elf32_Shdr *)ogn_map)->sh_link = new_value;
}

void	set_sh_info_32(void *ogn_map, uint64_t new_value)
{
	((Elf32_Shdr *)ogn_map)->sh_info = new_value;
}

void	set_sh_addralign_32(void *ogn_map, uint64_t new_value)
{
	((Elf32_Shdr *)ogn_map)->sh_addralign= new_value;
}

void	set_sh_entsize_32(void *ogn_map, uint64_t new_value)
{
	((Elf32_Shdr *)ogn_map)->sh_entsize = new_value;
}