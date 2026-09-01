/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_stub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:17:58 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/31 17:18:05 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../woody_woodpacker.h"

# define STUB64 "stub/stub64.o"
# define STUB32 "stub/stub32.o"

void	gather_stub_intel(t_intel *intel, t_intel *stub)
{
	if (intel->elf_caster == &ops_64)
	{
		retrieve_ogn_map(STUB64, stub);
		if (!check_prerequisite(stub))
		{
			munmap(stub->ogn_begin, stub->ogn_size);
			error_end("suspicious stub", 1, intel);
		}
	}
	else
		return ;
	ft_putendl_fd("stub intel", 1);
	gather_ehdr(stub);
	print_edhr_intel(stub);
	iterate_phdr(stub, print_phdr_intel);
}
