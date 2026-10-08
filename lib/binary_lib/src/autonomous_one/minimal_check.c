/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimal_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 04:49:16 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/07 04:50:48 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

uint64_t	compute_size(int fd)
{
	off_t	begin;
	off_t	end;

	begin = lseek(fd, 0, SEEK_CUR);
	end = lseek(fd, 0, SEEK_END);
	if (begin == -1 || end == -1 || lseek(fd, begin, SEEK_SET) == -1)
		return (0);
	return (end - begin);
}

int	open_mininal_map(int fd, void **map, uint64_t size)
{
	*map = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (*map == MAP_FAILED)
		return (0);
	return (1);
}

int	autonomous_get_Elf_Class(char *s)
{
	int			fd;
	uint64_t	to_ret;
	void		*map;
	uint64_t	size;

	to_ret = -1;
	map = NULL;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (((size = compute_size(fd)) > sizeof(Elf32_Ehdr)) && open_mininal_map(fd, &map, size))
	{
		to_ret = get_byte_type(map);
		munmap(map, size);
	}
	close(fd);
	return (to_ret);
}
