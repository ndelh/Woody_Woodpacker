/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 09:52:26 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 09:54:09 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

bool	open_copy_error(t_bin_file *file, int fd)
{
	if (fd == -1)
	{
		register_error("failed to open the document where copy should happen", file);
		return 1;
	}
	 if (syscall(SYS_ftruncate, fd, file->map_size) == -1)
    {
		register_error("failed to extend the document where copy should happen to needed size", file);
		close(fd);
		return 1;
	}
	return (0);
}

void	full_copy_doc(t_bin_file *file, char *target_doc)
{
	int		fd;
	void	*map;

	fd = open_wrapper(target_doc, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (open_copy_error(file, fd))
		return ;
	map = mmap(NULL, file->map_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd,  0);
	if (map == MAP_FAILED || map == NULL)
		register_error("failed to mmap the copy destination", file);
	else
		ft_memcpy(map, file->map, file->map_size);
	munmap(map, file->map_size); 
	close(fd);
}
