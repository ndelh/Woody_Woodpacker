/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 11:13:04 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/09 07:09:19 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

void	parse_gather(t_bin_data *data)
{
	first_parse(data);
	if ((data->stoppage))
		return ;
	gather_ehdr_content(data);
	parse_ehdr_content_range(data);
	//print_both_ehdr(data);
}


void	woody_core(t_bin_data *data)
{
	open_map(data);
	parse_gather(data);
	stripped_copy(data, "Woody");
	free_data(data);
}

int	main(int ac, char **argv)
{
	t_bin_data	*data;

	if (ac != 2)
	{
		ft_putendl_fd("invalid argument number", 2);
		exit(1);
	}
	if (autonomous_get_Elf_Class(argv[1]) == ELFCLASS64)
		data = init(argv[1], STUB64);
	else
	{
		ft_perror("unusable file");
		return (1);
	}
	woody_core(data);
}
