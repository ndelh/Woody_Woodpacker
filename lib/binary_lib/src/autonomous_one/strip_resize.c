/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 09:05:53 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/08 09:12:01 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	resize_after_strip(t_bin_file *file, t_bin_data *data, int fd)
{
	uint64_t	new_size;

	strip_shdr(file, data);
	new_size = retrieve_farthest_physical(file, data) + 1;
	//syscall(SYS_ftruncate, fd, new_size);
	(void)fd;
	file->map_size = new_size;
	printf("new_size %lu", new_size);
}
