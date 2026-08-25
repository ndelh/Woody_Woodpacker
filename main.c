/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:07:27 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/20 16:00:12 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

void	woody_core(char *s, t_intel *intel)
{
	retrieve_ogn_map(s, intel);
	if (!check_prerequisite(intel))
	{
		ft_putendl_fd("check_successfull", 1);
	}
	munmap(intel->ogn_begin, intel->ogn_size);
}

int	main(int ac, char **argv)
{
	t_intel		intel;
	
	if (ac != 2)
	{
		write(1, "no\n", 3);
		return (1);
	}
	ft_bzero(&intel, sizeof(struct s_intel));
	woody_core(argv[1], &intel);
}
