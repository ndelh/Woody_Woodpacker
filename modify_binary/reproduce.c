/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reproduce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 18:33:04 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/02 18:49:23 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"

uint64_t	compute_new_size(t_intel *intel)
{
	uint64_t	new_size;

	new_size = intel->ogn_size;
	new_size += PAGESIZE; //adding one pagesize, will be used to create space to padd after stub prog header is added, before the begining of prog header content
	new_size += (intel->stub_loader.content_size + 0xFFF) & ~0xFFFULL; //adding enought space for adding stub content size and maintain alignement;
	return (new_size);
}

void	*open_and_expand(t_intel *intel)
{
	int		fd;
	uint64_t	modified_size;
	void	*map;
	
	fd = open("Woody", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		perror("read error");
	modified_size = compute_new_size(intel);
	syscall(SYS_ftruncate, fd, modified_size);
	map = mmap(NULL, modified_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (map == MAP_FAILED)
		perror("map failed");
	close(fd);
	return (map);
	//add_error_case;
}

void	reproduce(t_intel *intel)
{
	void		*to_inject;
	uint64_t	phdr_begin;
	
	to_inject = open_and_expand(intel);
	phdr_begin = intel->bin_data.phdr_offset;
	ft_memcpy(to_inject, intel->ogn_begin, intel->ogn_size);
	munmap(to_inject, intel->ogn_size);
}
