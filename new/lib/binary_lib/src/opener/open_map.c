/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:30:00 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 18:29:49 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	open_fd(t_bin_data *data, t_bin_file *file)
{
	file->fd = open(file->path, O_RDWR);
	if (file->fd == -1)
		register_error(data, "open failed", file);	
}

void	compute_map_size(t_bin_data *data, t_bin_file *file)
{
	off_t	begin;
	off_t	end;
	int		fd;

	if (file->fd == -1)
		return ;
	fd = file->fd;
	begin = lseek(fd, 0, SEEK_CUR);
	end = lseek(fd, 0, SEEK_END);
	if (begin == -1 || end == -1 || lseek(fd, begin, SEEK_SET) == -1)
		register_error(data, "atleast one lseek call failed", file);
	file->map_size = end - begin;
}

void	open_mmap(t_bin_data *data, t_bin_file *file)
{
	file->map = mmap(NULL, file->map_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, file->fd, 0);
	if (data->core->map == MAP_FAILED)
		register_error(data, "mmap_failed", file);
}

void	process_whole_opening(t_bin_data *data, t_bin_file *file)
{	
	open_fd(data, file);
	if (data->stoppage)
		return ;
	compute_map_size(data, file);
	if (data->stoppage)
		return ;
	open_mmap(data, file);
}

void	open_map(t_bin_data *data)
{
	process_whole_opening(data, data->core);
	if (data->stub)
		process_whole_opening(data, data->stub);
}
