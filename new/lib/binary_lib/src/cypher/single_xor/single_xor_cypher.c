/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_xor_cypher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 05:11:57 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/05 06:21:17 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

typedef struct s_simple_cypher
{
	void	*key;
	void	*place_holder;
}	t_simple_cypher;


void	load_phdr_intel_in_stub(void *helper, uint64_t content_load_addr, uint64_t content_size, uint64_t current_perm)
{
	uint64_t	*place_holder;

	place_holder = ((t_simple_cypher *)helper)->place_holder;
	*place_holder = content_load_addr;
	++place_holder;
	*place_holder = content_size;
	++place_holder;
	*place_holder = current_perm;
	++place_holder;
	((t_simple_cypher *)helper)->place_holder = place_holder;
}

void	cypher_all_pt_load(t_bin_file *file, void *helper, void *cursor)
{
	const t_elf_ops	*elf_caster;
	t_simple_cypher	*s_cypher;
	unsigned char	*content_begin;
	uint64_t		content_offset;
	uint64_t		content_load_addr;
	uint64_t		content_size;
	uint64_t		current_perm;

	
	s_cypher = helper;
	elf_caster = file->elf_caster;
	if (elf_caster->get_ptype(cursor) != PT_LOAD)
		return ;
	content_offset = elf_caster->get_poffsset(cursor);
	if (!(elf_caster->get_pflags(cursor) & PF_X)) //this is temporarily zill uncypher the other later
		return ;
	if (!content_offset)
		return ;
	content_begin = (unsigned char *)file->map + content_offset;
	content_size = elf_caster->get_pfilesz(cursor);
	current_perm = elf_caster->get_pflags(cursor);
	content_load_addr = elf_caster->get_pvaddr(cursor);
	s_xor_cypher_s(content_begin, content_size, s_cypher->key);
	load_phdr_intel_in_stub(helper, content_load_addr, content_size, current_perm);
}

void	cypher_pt_load(t_bin_file *target, t_bin_file *stub)
{
	t_simple_cypher	helper;
	uint64_t	*related_place_holder;

	ft_bzero(&helper, sizeof(t_simple_cypher));
	related_place_holder = (uint64_t *)stub->stub_data->canaries_begin;
	related_place_holder += KEY_PLACE_HOLDER_BEGIN;
	helper.key = gen_random_key(32);
	ft_memcpy(related_place_holder, helper.key, 32);
	related_place_holder += 4;
	helper.place_holder = related_place_holder;
	iter_phdr(target, &helper, cypher_all_pt_load);
	free(helper.key);
}

