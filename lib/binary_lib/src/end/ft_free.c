/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 12:31:14 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/06 12:38:04 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	close_add(t_bin_data *data)
{
	if (data->copy_fd != -1)
		close(data->copy_fd);
	if (data->map_copy != MAP_FAILED)
		munmap(data->map_copy, data->copy_size);
}

void	close_map(t_bin_file *file)
{
	if (file)
	{
		if (file->map != MAP_FAILED)
			munmap(file->map, file->map_size);
		if (file->fd != -1)
			close(file->fd);
	}
}

void	free_intel(t_bin_file *file)
{
	if (file->intel)
		free(file->intel);
	free(file);
}

void	free_data(t_bin_data *data)
{
	if (!data)
		return ;
	close_add(data);
	if (data->core)
	{
		close_map(data->core);
		free_intel(data->core);
	}
	if (data->stub)
	{	
		close_map(data->stub);
		free_intel(data->stub);
	}
	if (data->stub_injector)
		free(data->stub_injector);
	free(data);
}
