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
	printf("phdr type: " COLOR_GREEN);
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
	printf(COLOR_RESET);
}

void	print_memory_right(uint64_t flags)
{
	printf(COLOR_PURPLE "Permission in RAM: " COLOR_RESET);
	if (!flags)
		printf("NONE\n");
	if (flags & PF_X)
		printf(COLOR_RED "X | " COLOR_RESET);
	if (flags & PF_W)
		printf(COLOR_GREEN "W | " COLOR_RESET);
	if (flags & PF_R)
		printf(COLOR_BLUE "R" COLOR_RESET);
	printf("\n");
}

void	print_phdr_data(void *cursor, const t_elf_ops *elf_caster)
{
	uint64_t	pvaddr;
	uint64_t	pvaddr_end;

	pvaddr = elf_caster->get_pvaddr(cursor);
	pvaddr_end = pvaddr + elf_caster->get_pmemsz(cursor);
	printf(COLOR_BLUE "file related data:\n" COLOR_RESET);
	printf("poffset: %lu\n", elf_caster->get_poffsset(cursor));
	printf("pfilesz: %lu\n", elf_caster->get_pfilesz(cursor));
	printf(COLOR_GREEN "memory related data:\n" COLOR_RESET);
	printf("pmemsz: %lu\n", elf_caster->get_pmemsz(cursor));
	printf("bss_size: %lu\n", find_bss_size(elf_caster, cursor));
	printf("begin of sement in memory: 0x%lx, not hex: %lu\n", pvaddr, pvaddr);
	printf("end of segment in memory: 0x%lx, not hex %lu\n", pvaddr_end, pvaddr_end);
	print_memory_right(elf_caster->get_pflags(cursor));
}

void	print_phdr(t_bin_file *file, void *aux_data, void *cursor)
{
	const t_elf_ops	*elf_caster;
	uint8_t		*count;
	uint64_t	type;
	
	count = (uint8_t *)aux_data;
	++(*count);
	elf_caster = file->elf_caster;
	printf(COLOR_RED "phdr nb: %i\n" COLOR_RESET, *count);
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
