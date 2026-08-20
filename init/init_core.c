/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:52:49 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/20 17:03:00 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"

void	ft_map_compute(t_intel *intel)
{

	intel->ogn_begin = mmap(NULL, L)
}

void	ft_open(char *s, t_intel *intel)
{	
	intel->ogn_fd = open(s, O_WRONLY);
	if (intel->ogn_fd == -1)
	{
		ft_perror("file passed as argument cannot be opened");
		exit(1);
	}
	intel->woody_fd = open("woody", O_WRONLY | O_CREAT, 755);
	if (intel->woody_fd == -1)
	{
		ft_perror("file Woody, destined to receive packed biinary cannot be created or open");
		close(intel->ogn_fd);
		exit(1);
	}

}

void	init_core(char *s, t_intel *intel)
{
	ft_open(s, intel);
	ft_map_compute(intel);
}
