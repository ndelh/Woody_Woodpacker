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

void	close_map(t_bin_file *file)
{
	if (file->map != MAP_FAILED)
		munmap(file->map, file->map_size);
	if (file->fd != -1)
			close(file->fd);
}

void	free_file(t_bin_file *file)
{
	if (!file )
		return ;
	close_map(file);
	if (file->intel)
		free(file->intel);
	free(file);
}