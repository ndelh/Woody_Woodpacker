/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shdr_setter_64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 19:25:27 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/10 19:25:37 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	set_sh_name_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Shdr *)ogn_map)->sh_name = new_value;
}

void	set_sh_type_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Shdr *)ogn_map)->sh_type = new_value;
}

void	set_sh_flags_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Shdr *)ogn_map)->sh_flags = new_value;
}

void	set_sh_addr_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Shdr *)ogn_map)->sh_addr = new_value;
}

void	set_sh_offset_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Shdr *)ogn_map)->sh_offset = new_value;
}

void	set_sh_size_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Shdr *)ogn_map)->sh_size = new_value;
}

void	set_sh_link_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Shdr *)ogn_map)->sh_link = new_value;
}

void	set_sh_info_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Shdr *)ogn_map)->sh_info = new_value;
}

void	set_sh_addralign_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Shdr *)ogn_map)->sh_addralign= new_value;
}

void	set_sh_entsize_64(void *ogn_map, uint64_t new_value)
{
	((Elf64_Shdr *)ogn_map)->sh_entsize = new_value;
}