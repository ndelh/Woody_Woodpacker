/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_xor_cypher_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 17:20:49 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/30 17:21:05 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

typedef struct s_simple_cypher
{
	void	*key;
	void	*place_holder;
}	t_simple_cypher;

uint64_t	convert_elf_perm_to_posix(uint64_t current_perm)
{
	uint64_t	converted;

	converted = 0;
	if (current_perm & PF_X)
		converted |= PROT_EXEC;
	if (current_perm != PF_W)
		converted |= PROT_WRITE;
	if (current_perm & PF_R)
		converted |= PROT_READ;
	return converted;
}

void    load_s_xor_intel_64(void *helper, uint64_t content_load_addr, uint64_t content_size, uint64_t current_perm)
{
	uint64_t	*place_holder;
    
    place_holder = ((t_simple_cypher *)helper)->place_holder;
	*place_holder = content_load_addr;
	++place_holder;
	*place_holder = content_size;
	++place_holder;
	*place_holder = convert_elf_perm_to_posix(current_perm);
	++place_holder;
	((t_simple_cypher *)helper)->place_holder = place_holder;
}

void    load_s_xor_intel_32(void *helper, uint64_t content_load_addr, uint64_t content_size, uint64_t current_perm)
{
	uint32_t	*place_holder;
    
    place_holder = ((t_simple_cypher *)helper)->place_holder;
	*place_holder = (uint32_t)content_load_addr;
	++place_holder;
	*place_holder = content_size;
	++place_holder;
	*place_holder = (uint32_t)convert_elf_perm_to_posix(current_perm);
	++place_holder;
	((t_simple_cypher *)helper)->place_holder = place_holder;
}
