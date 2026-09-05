/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 13:48:29 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/30 17:20:42 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"

char	*ehdr_tab[10] = {
	"entry point value hex:",
	"not hex:",
	"program header section start:",
	"program header struct number:",
	"program header struct size:",
	"section header section start:",
	"section header struct number:",
	"section header struct size:",
	"strtab index:",
	""
};

char	*phdr_tab[9] = {
	"ptype:",
	"segment file offset:",
	"segment_virtual adress:",
	"segment physical adress:",
	"segment size in file:",
	"segment size in memory:",
	"segment flags",
	"segment alignement",
	"",
};

void	print_edhr_intel(t_intel *intel)
{
	t_elf_navigator	*nav;
	int	i;

	i = 0;
	nav = &intel->bin_data;
	cr(1);
	printf("%s 0x%lx", ehdr_tab[i++], nav->entry);
	printf(", %s %lu\n", ehdr_tab[i++], nav->entry);
	printf("%s %lu\n", ehdr_tab[i++], nav->phdr_offset);
	printf("%s %lu\n", ehdr_tab[i++], nav->phdr_num);
	printf("%s %lu\n", ehdr_tab[i++], nav->phdr_size);
	printf("%s %lu\n", ehdr_tab[i++], nav->shdr_offset);
	printf("%s %lu\n", ehdr_tab[i++], nav->shdr_num);
	printf("%s %lu\n", ehdr_tab[i++], nav->shdr_size);
	printf("%s %lu\n", ehdr_tab[i++], nav->shstrndx);
	cr(1);
}

void	print_phdr_type(uint64_t type)
{
	printf("%s ", phdr_tab[0]);
	if (type == 0)
		printf("PT_NULL\n");
	else if (type == 1)
		printf("PT_LOAD , loading segment\n");
	else if (type == 2)
		printf("PT_DYNAMIC, dynamic linking intel\n");
	else if (type == PT_INTERP)
		printf("PT_INTEREP, programm interpreter\n");
	else if (type == PT_NOTE)
		printf("PT_NOTE, no impact on exec but not the best idea\n");
	else if (type == PT_SHLIB)
		printf("PT_SHLIB not supposed to happen\n");
	else if (type == PT_PHDR)
		printf("PT_PHDR, mirror phdr state\n");
	else if (type == PT_TLS)
		printf("PT_TLS, thread local segment\n");
	else
		printf("irrelevant for the moment\n");
}

void	print_phdr_intel(t_intel *intel, void *cursor)
{
	const t_elf_ops		*caster;
	static int		i;
	int			j;

	j = 1;
	printf("for program header number: %i\n", i++);
	caster = intel->elf_caster;
	print_phdr_type(caster->get_ptype(cursor));
	printf("%s %lu\n", phdr_tab[j++], caster->get_poffsset(cursor));
	printf("%s %lu\n", phdr_tab[j++], caster->get_pvaddr(cursor));
	printf("%s %lu\n", phdr_tab[j++], caster->get_paddr(cursor));
	printf("%s %lu\n", phdr_tab[j++], caster->get_pfilesz(cursor));
	printf("%s %lu\n", phdr_tab[j++], caster->get_pmemsz(cursor));
	printf("%s %lu\n", phdr_tab[j++], caster->get_pflags(cursor));
	printf("%s %lu\n", phdr_tab[j++], caster->get_palign(cursor));
	cr(1);
}

void	print_strtab(t_intel *intel)
{
	t_elf_navigator	*nav;
	uint64_t		len;
	unsigned char	*cursor;

	nav = &intel->bin_data;
	len = nav->strtab_len;
	printf("printlen %lu\n", len);
	cursor = nav->strtab_begin;
	cr(1);
	printf("strtab of: %s\n", intel->binary_name);
	while (len)
	{
		if (*cursor)
			write(1, cursor, 1);
		else
			write(1, "\n", 1);
		++cursor;
		--len;
	}
	cr(1);
}
