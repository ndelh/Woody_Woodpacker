/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_phdr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:14:19 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/23 15:53:53 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	print_special_ptype(uint64_t type, t_bin_file *file)
{
	if (type == PT_LOOS)
		printf("PT_LOOS\n");
	else if (type == PT_GNU_EH_FRAME)
		printf("PT_GNU_EH_FRAME\n");
	else if (type == PT_GNU_STACK)
		printf("PT_GNU_STACK\n");
	else if (type == PT_GNU_RELRO)
		printf("PT_GNU_RELRO\n");
	else if (type == PT_GNU_PROPERTY)
		printf("PT_GNU_PROPERTY\n");
	else
		file_warning("sun system type or unknown type", file);
}

void	print_ptype(uint64_t type, t_bin_file *file)
{
	printf(COLOR_BLUE);
	printf("phdr type:");
	printf(COLOR_YELLOW);
	printf(" ");
	if (type == PT_LOAD)
		printf("PT_LOAD\n");
	else if (type == PT_NOTE)
		printf("PT_NOTE\n");
	else if (type == PT_NULL)
		printf("PT_NULL\n");
	else if (type == PT_DYNAMIC)
		printf("PT_DYNAMIC\n");
	else if (type == PT_INTERP)
		printf("PT_INTERP\n");
	else if (type == PT_SHLIB)
		printf("PT_SHLIB\n");
	else if (type == PT_PHDR)
		printf("PT_PHDR\n");
	else if (type == PT_TLS)
		printf("PT_TLS\n");
	else if (type >= PT_NUM)
		print_special_ptype(type, file);
}

void	print_phdr_data(void *cursor, const t_elf_ops *elf_caster)
{
	printf("pfilesz: %lu\n", elf_caster->get_pfilesz(cursor));
	printf("pmemsz: %lu\n", elf_caster->get_pmemsz(cursor));
	printf("diff between pfilesz and pmemsz %lu\n", find_bss_size(elf_caster, cursor));
}

void	print_phdr(t_bin_file *file, void *aux_data, void *cursor)
{
	const t_elf_ops	*elf_caster;
	uint8_t		*count;
	uint64_t	type;
	
	count = (uint8_t *)aux_data;
	++(*count);
	elf_caster = file->elf_caster;
	printf(COLOR_RED);
	printf("phdr nb: %i\n", *count);
	printf(COLOR_RESET);
	type = elf_caster->get_ptype(cursor);
	print_ptype(type, file);
	print_phdr_data(cursor, elf_caster);
	CR_DEFAULT;
}

void	print_all_phdr(t_bin_file *file)
{
	uint8_t	phdr_nb;

	phdr_nb = 0;
	iter_phdr(file, &phdr_nb, print_phdr);
}
