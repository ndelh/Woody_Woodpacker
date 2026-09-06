/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ehdr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 21:07:36 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/06 21:08:28 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	print_ehdr(t_bin_file *file)
{
	t_file_intel	*intel;

	intel = file->intel;

	ft_putstr_fd("printing ehdr value for: " , 1);
	ft_putendl_fd(file->path, 1);
	printf("entrypoint adress: 0x%lx not hex: %lu\n", intel->e_entry, intel->e_entry);
	printf("start of program header: %lu\n", intel->phdr_offset);
	printf("start of section header: %lu\n", intel->shdr_offset);
	printf("size of program header: %lu\n", intel->phdr_size);
	printf("size of section %lu\n", intel->shdr_size);
	printf("phdr number: %lu\n", intel->phdr_num);
	printf("shdr nummber: 0x%lu\n", intel->shdr_num);
	printf("Section header string table index: %lu\n", intel->shstrtab_index);
	printf("strtab size: %lu\n", intel->strtab_size);
	cr(STDIN_FILENO);
}

void	print_both_ehdr(t_bin_data *data)
{
	ft_putendl_fd("printing all ehdr content", STDIN_FILENO);
	cr(STDIN_FILENO);
	print_ehdr(data->core);
	if (data->stub)
		print_ehdr(data->stub);
}
