/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:18:50 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 17:34:30 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

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

void	ft_end(t_bin_data *data, int error_code)
{
	close_map(data->core);
	close_map(data->stub);
	exit(error_code);
}
