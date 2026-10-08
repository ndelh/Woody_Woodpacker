/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_extend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 23:14:42 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/06 23:15:49 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	open_extend(t_bin_data *data, char *s)
{
    data->copy_fd = open(s, O_CREAT | O_TRUNC | O_RDWR, 0777);
    if (data->copy_fd == -1)
    {
        register_error(data, "failed to open the destination for the copy file", NULL);
        return ;
    }
    if ((syscall(SYS_ftruncate, data->copy_fd, data->copy_size)) == -1)
    {
        register_error(data, "failed to truncate the copy file", NULL);
        return ;
    }
    data->map_copy = mmap(NULL, data->copy_size, PROT_READ | PROT_WRITE, MAP_SHARED, data->copy_fd, 0);
    if (data->map_copy == MAP_FAILED)
        register_error(data, "mmap failed for the copy file", NULL);
}
