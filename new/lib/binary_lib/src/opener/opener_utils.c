/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opener_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:48:44 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/08 15:51:05 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

int    open_wrapper(char *s, int flags, int perm)
{
	int fd;
	
    if (!perm) 
	    fd = open(s, flags);
    else
        fd = open(s, flags, perm);
    if (fd == -1)
    perror("failed open");
	return (fd);
}

void	open_mmap_file(t_bin_file *file, int prot, int flag)
{
	file->map = mmap(NULL, file->map_size, prot, flag, file->fd, 0);
	if (file->map == MAP_FAILED || file->map == NULL)
    {
        perror("mmap failed");
		register_error("mmap_failed", file);
    }
}

void	compute_map_size(t_bin_file *file)
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
		register_error("atleast one lseek call failed", file);
	file->map_size = end - begin;
}

void    extend_file(int fd, uint64_t added_size, uint64_t old_size, t_bin_file *file)
{
    if (syscall(SYS_ftruncate, fd, added_size + old_size) == -1)
        register_error("failed to extend the file to needed size", file);
    else
        file->map_size += added_size;
}
