/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 11:15:14 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/23 12:09:53 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"
#include "report.h"

void	report(char *file_name, uint8_t flags)
{
	t_bin_file	*file;
	if (!file_name)
		return ;
	file = get_read_only_file(file_name);
	if (!file)
		return ;
	parse_all(file);
	if (file->dead)
	{
		register_error("cannot_print due to file error", file);
		free_file(file);
		return ;
	}
	print_ehdr(file);
	if (flags & 1)
		print_all_phdr(file);
	if (flags & 2)
		printf("must print shdr");
	free_file(file);
}
