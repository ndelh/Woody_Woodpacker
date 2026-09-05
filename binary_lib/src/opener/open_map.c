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

void	open_fd(t_bin_data *data)
{
	data->core->fd = open(data->core->path, O_RDWR);
	if (data->stub)
		data->stub->fd = open(data->stub->path, O_RDWR);
	if (data->core->fd == -1 || (data->stub && data->stub->fd == -1))
		DEFAULT_ERROR(data);
}

void	map_data(t_bin_data *data)
{
	data->core->map = mmap(NULL, data->core->map_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, data->core->fd, 0);
	if (data->core->map == MAP_FAILED)
	{
		perror("binary mmap failed:");
		DEFAULT_ERROR(data);
	}
	if (!data->stub)
		return ;
	data->stub->map = mmap(NULL, data->stub->map_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, data->stub->fd, 0);
	if (data->stub->map == MAP_FAILED)
	{
		perror("stub mmap failed:");
		DEFAULT_ERROR(data);
	}
}

void	open_map(t_bin_data *data)
{
	open_fd(data);
	compute_map_size(data);
	map_data(data);
}
