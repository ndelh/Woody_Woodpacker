/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 13:48:29 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/27 14:00:40 by ndelhota         ###   ########.fr       */
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

void	print_phdr_intel(t_intel *intel);