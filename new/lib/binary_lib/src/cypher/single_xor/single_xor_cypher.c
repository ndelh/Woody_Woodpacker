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

void	*generate_key(t_bin_data *data)
{
	int	fd;
	char	*s;
	
	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
	{
		register_error(data, "failed to open /dev/urandom wich is used as a way to generate key", data->core);
		return (NULL);
	}
	s = malloc(32);
	if (!s)
		register_error(data, "encryption key malloc failed", data->core);
	if (s && read(fd, s, 32) != 32)
		register_error(data, "failed to process read on encryption key", data->core);
	close(fd);
	return ((void *)s);
}

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

void	cypher_all_pt_load(t_bin_file *file, t_bin_data *data, void *helper, void *cursor)
{
	const t_elf_ops	*elf_caster;
	t_simple_cypher	*s_cypher;
	unsigned char	*content_begin;
	uint64_t		content_offset;
	uint64_t		content_load_addr;
	uint64_t		content_size;
	uint64_t		current_perm;

	(void)data;
	s_cypher = helper;
	elf_caster = file->elf_caster;
	if (elf_caster->get_ptype(cursor) != PT_LOAD)
		return ;
	content_offset = elf_caster->get_poffsset(cursor);
	if (!content_offset)
		return ;
	content_begin = (unsigned char *)file->map + content_offset;
	content_size = elf_caster->get_pfilesz(cursor);
	current_perm = elf_caster->get_pflags(cursor);
	content_load_addr = elf_caster->get_pvaddr(cursor);
	s_xor_cypher_s(content_begin, content_size, s_cypher->key);
	load_phdr_intel_in_stub(helper, content_load_addr, content_size, current_perm);
}

void	cypher_pt_load(t_bin_data *data)
{
	t_simple_cypher	helper;
	uint64_t	*related_place_holder;

	ft_bzero(&helper, sizeof(t_simple_cypher));
	related_place_holder = (uint64_t *)data->stub_injector->current_placeholder;
	related_place_holder += PHDR_PLACE_HOLDER_BEGIN;
	helper.key = generate_key(data);
	helper.place_holder = related_place_holder;
	iterate_phdr(data->core, data, &helper, cypher_all_pt_load);
	free(helper.key);
}

