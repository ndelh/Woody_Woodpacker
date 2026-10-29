/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stub_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 08:10:17 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/27 14:25:48 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	compute_ep_offset_64(t_bin_file *file, t_bin_file *stub, uint64_t oep, uint64_t new_ep)
{
	const t_elf_ops	*elf_caster;
	uint64_t		*place_holder;

	elf_caster = file->elf_caster;
	place_holder = (uint64_t *)stub->stub_data->canaries_begin;
	if (is_inf(oep, new_ep))
	{
		*place_holder = new_ep - oep;
		++place_holder;
		*place_holder = 0;
	}
    else
	{
		*place_holder = oep - new_ep;
		++place_holder;
		*place_holder = 1;
    }
	++place_holder;
	*place_holder = oep;

}

void	compute_ep_offset_32(t_bin_file *file, t_bin_file *stub, uint64_t oep, uint64_t new_ep)
{
	const t_elf_ops	*elf_caster;
	uint32_t		*place_holder;

	elf_caster = file->elf_caster;
	place_holder = (uint32_t *)stub->stub_data->canaries_begin;
	// printf("old_oep %lx\n", oep);
	// printf("new_eop %lx\n", new_ep );
	// if (is_inf(oep, new_ep))
	// {
	// 	*place_holder = new_ep - oep;
	// 	++place_holder;
	// 	*place_holder = 0;
	// }
    // else
	// {
	// 	*place_holder = oep - new_ep;
	// 	++place_holder;
	// 	*place_holder = 1;
    // }
	// ++place_holder;
	// *place_holder = oep;
	*(place_holder + 2) = oep;
	(void)new_ep;
}

void	print_stub_hard_content_32(uint32_t *canaries)
{
	uint64_t	canaries_nb;

	canaries_nb = CANARY_NB_32;
	while (canaries_nb--)
	{
		printf("canary_line: %lu", CANARY_NB_32 - canaries_nb);
		if (*canaries == CANARY_VALUE_32)
			printf("untouched line\n");
		else
			printf("value hex: %x, value not hex %u\n", *canaries, *canaries);
		++canaries;
		cr(1);
	}
}


//first placeholder contain the diff between the two entrypoint, second contain the growth direction 
void	compute_ep_offset(t_bin_file *file, t_bin_file *stub, uint64_t oep, uint64_t new_ep)
{
		if (get_byte_type(file->map) == ELFCLASS64)
			compute_ep_offset_64(file, stub, oep, new_ep);
		else
		{
			compute_ep_offset_32(file, stub, oep, new_ep);
			print_stub_hard_content_32(stub->stub_data->canaries_begin);
		}
}
