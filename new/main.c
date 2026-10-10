/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:42:35 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/10 15:46:27 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

int	main(int ac, char **argv)
{

	if (ac != 2)
		return 0;
	free_standing_stubbing(argv[1], "Woody", 1);
	barbarious_strip("Woody");
}
