/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content_range.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 20:09:37 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 20:15:59 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	main_range_check(t_bin_file *file)
{
	t_file_intel	*intel;
	
	intel = file->intel;
    if (is_struct_oob(file, intel->shdr_offset, intel->shdr_num, intel->shdr_size))
        register_error("dubious shdr range", file);
    if (is_struct_oob(file, intel->phdr_offset, intel->phdr_num, intel->phdr_size))
         register_error("dubious phdr range", file);
}


// void    ehdr_range_checker(t_bin_data *data, t_bin_file *file)
// {
//     if (data->stoppage)
//         return ;
//     iterate_shdr(file, data, NULL, shdr_range_check);
//     iterate_phdr(file, data, NULL, phdr_range_check);
// }

void    parse_ehdr_size_intel(t_bin_file *file)
{
    int phdr_size;
    int shdr_size;
    int ehdr_size;

    phdr_size = file->intel->phdr_size;
    shdr_size = file->intel->shdr_size;
    ehdr_size = file->intel->e_ehsize;
    if (file->elf_caster == &ops_64)
    {
        if (ehdr_size != sizeof(Elf64_Ehdr))
            register_error("fallacious main headersize\n", file);
        if (phdr_size && phdr_size != sizeof(Elf64_Phdr))
            register_error("fallacious program header size\n", file);
        if (shdr_size && shdr_size != sizeof(Elf64_Shdr))
            register_error("fallacious shdr_size", file);
    }
}

void	parse_ehdr_content(t_bin_file *file)
{
    file_launcher(file, parse_ehdr_size_intel);
    file_launcher(file, main_range_check);
}

