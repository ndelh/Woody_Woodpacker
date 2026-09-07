/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 11:13:04 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/07 04:18:59 by ndelhota         ###   ########.fr       */
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

void	modify(t_bin_data *data)
{
	strip_shdr(data->core, data); 
}

void	woody_core(t_bin_data *data)
{
	open_map(data);
	parse_gather(data);
	open_basic_cpy(data, "Woody");
	find_shdr_by_name(data->core, data, ".text");
	modify(data);
	simple_cpy(data);
	free_data(data);
}

int	main(int ac, char **argv)
{
	t_bin_data	*data;

	if (ac != 3)
	{
		ft_putendl_fd("invalid argument number", 2);
		exit(1);
	}
	data = init(argv[1], argv[2]);
	woody_core(data);
}
