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

// void	find_place_holder(t_stub_loader *stub_loader)
// {
// 	unsigned char *s()
// }

void	gather_stub_payload(t_intel *intel, t_intel *stub)
{
	iterate_shdr(stub, retrieve_txt_shdr);
	printf("size: %lx\n", stub->stub_loader.content_size);
	retrieve_placeholder(stub); //fetch pointer on first stub payload
	iterate_phdr(intel, retrieve_available_adrr); //fetch first available vadrr value;
	align_available_adress(intel); // align vadrr 
	printf("vaddr for stub not hex: %lu , hex: 0x%lx", intel->stub_loader.av_addr, intel->stub_loader.av_addr);
}

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
	gather_stub_payload(intel, stub);
}
