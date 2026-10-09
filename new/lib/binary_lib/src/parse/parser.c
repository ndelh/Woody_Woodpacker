/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:07:16 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/08 18:20:57 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	create_intel(t_bin_file *file)
{
	if (file->intel == NULL)
		file->intel = malloc(sizeof(t_file_intel));
	if (file->intel == NULL)
		register_error("failed to allocate ehdr intel struct", file);
	else
		ft_bzero(file->intel, sizeof(t_file_intel));
}

void	parse_all(t_bin_file *file)
{
	file_launcher(file, first_parse);
	file_launcher(file, create_intel);
	file_launcher(file, load_ehdr_content);
	file_launcher(file, parse_ehdr_content);
	file_launcher(file, shstrndx_validity);
}
