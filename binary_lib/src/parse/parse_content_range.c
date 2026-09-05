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
        ft_end_msg(data, STDERR_FILENO, "dubious shdr range");
    if (is_struct_oob(file, intel->phdr_offset, intel->phdr_num, intel->phdr_size))
         ft_end_msg(data, STDERR_FILENO, "dubious phdr range");
    if (intel->shstrtab_index >= intel->shdr_num)
            ft_end_msg(data, STDERR_FILENO, "strtab index located outside of phdr section");
}

void	parse_content_range(t_bin_data *data)
{
	main_range_check(data->core, data);
}
