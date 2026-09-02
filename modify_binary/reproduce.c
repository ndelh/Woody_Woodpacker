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

void	*open_and_expand(t_intel *intel)
{
	int		fd;
	void	*map;
	
	fd = open("Woody", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		perror("read error");
	syscall(SYS_ftruncate, fd, intel->ogn_size);
	map = mmap(NULL, intel->ogn_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (map == MAP_FAILED)
		perror("map failed");
	close(fd);
	return (map);
	//add_error_case;
}

void	reproduce(t_intel *intel)
{
	void	*to_inject;
	
	to_inject = open_and_expand(intel);
	ft_memcpy(to_inject, intel->ogn_begin, intel->ogn_size);
	munmap(to_inject, intel->ogn_size);
}
