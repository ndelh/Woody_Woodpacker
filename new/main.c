/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 11:13:04 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/13 19:55:43 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

void	ft_end(t_bin_data *data, int exit_code)
{
	free_data(data);
	exit(exit_code);	
}

void	launcher(t_bin_data *data, void(*func)(t_bin_data *data))
{
	if (data->stoppage)
		ft_end(data, 1);
	func(data);
}

void	parse_gather(t_bin_data *data)
{
	launcher(data, first_parse);
	gather_ehdr_content(data);
	parse_ehdr_content_range(data);
	//print_both_ehdr(data);
}


void	woody_core(t_bin_data *data)
{
	launcher(data, open_map);
	launcher(data, parse_gather);
	//fs_basic_stub_copy(data, "Woody");
	fs_caving_stub(data, "Woody");
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
