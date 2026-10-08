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

void	main_range_check(t_bin_file *file, t_bin_data *data)
{
	t_file_intel	*intel;
	
	intel = file->intel;
    if (is_struct_oob(file, intel->shdr_offset, intel->shdr_num, intel->shdr_num))
        register_error(data, "dubious shdr range", file);
    if (is_struct_oob(file, intel->phdr_offset, intel->phdr_num, intel->phdr_size))
         register_error(data, "dubious phdr range", file);
	shstrndx_validity(file, data);
}


void    ehdr_range_checker(t_bin_data *data, t_bin_file *file)
{
    main_range_check(file, data);
    if (data->stoppage)
        return ;
    iterate_shdr(file, data, NULL, shdr_range_check);
    iterate_phdr(file, data, NULL, phdr_range_check);

}

void	parse_ehdr_content_range(t_bin_data *data)
{
    ehdr_range_checker(data, data->core);
    if (data->stub)
        ehdr_range_checker(data, data->stub);
}

