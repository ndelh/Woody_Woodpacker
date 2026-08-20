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
	init_core(s, intel);
}

int	main(int ac, char **argv)
{
	t_intel		intel;
	
	if (ac < 3)
	{
		write(1, "no\n", 3);
		return (1);
	}
	ft_bzero(&intel, sizeof(struct s_intel));
	woody_core(argv[1], &intel);
}
