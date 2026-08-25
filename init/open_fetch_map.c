/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fetch_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 16:19:32 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/21 17:33:55 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"

void	compute_map_size(int ogn_fd, t_intel *intel)
{
	off_t begin;
	off_t end;

	begin = lseek(ogn_fd, 0, SEEK_CUR);
	end = lseek(ogn_fd, 0, SEEK_END);
	if (end == -1 || begin == -1)
		ft_perror("lseek failed");
	intel->ogn_size = end - begin;
	lseek(ogn_fd, begin, SEEK_SET);
}

//to do add a proper ft end to treat lseek fail and mmap fail

void	mmap_binary(int fd, t_intel *intel)
{
	intel->ogn_begin = mmap(NULL, intel->ogn_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);
	if (intel->ogn_begin == MAP_FAILED)
	{
		ft_perror("mmap failed");
		exit(1); // need to to add proper end to this too
	}
}

void	retrieve_ogn_map(char *s, t_intel *intel)
{
	int ogn_fd;

	if ((ogn_fd = open(s, O_RDWR)) == -1)
	{
		perror("");
		ft_perror("file passed as argument cannot be opened");
		exit(1);
	}
	compute_map_size(ogn_fd, intel);
	mmap_binary(ogn_fd, intel);
}
