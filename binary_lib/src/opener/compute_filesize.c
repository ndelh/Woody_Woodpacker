/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_filesize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:44:12 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 17:32:28 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

int	compute_size(int fd, t_bin_data *data)
{
	off_t	begin;
	off_t	end;

	begin = lseek(fd, 0, SEEK_CUR);
	end = lseek(fd, 0, SEEK_END);
	if (begin == -1 || end == -1)
	{
		perror("lseek failed");
		DEFAULT_ERROR(data);	
	}
	lseek(fd, begin, SEEK_SET);
	return (end - begin);
}

void	compute_map_size(t_bin_data *data)
{
	data->core->map_size = compute_size(data->core->fd, data);
	if (data->stub)
		data->stub->map_size = compute_size(data->stub->fd, data);
}
