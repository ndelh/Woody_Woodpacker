/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freestanding_stubbing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 09:36:23 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 11:54:21 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

t_bin_file *get_stub(uint64_t flags)
{
	t_bin_file	*file;

	if (flags == ELFCLASS64)
		file = get_writable_unshared_file(STUB64);
	else
		file = get_writable_unshared_file(STUB32);
	file_launcher(file, parse_all);
	return (file);
}

void	process_stub(t_bin_file *tmp_file, bool cypher)
{
	t_bin_file	*stub;

	if (tmp_file->dead)
		return ;
	stub = get_stub(get_byte_type(tmp_file->map));
	file_launcher(stub, gather_fs_stub_data);
	tmp_file->dead = stub->dead;
	if (tmp_file->dead == 0)
		freestanding_caving_stub(tmp_file, stub, cypher);
	if (stub)
		free_file(stub);
}


void	free_standing_stubbing(char *og_filename, char *new_filename, bool cypher)
{
	char	*tmp_filename;
	t_bin_file *tmp_file;


	if ((tmp_filename = gen_random_key(32)) == NULL)
		return ;
	tmp_file = get_modifiable_copy(og_filename, tmp_filename);
	parse_all(tmp_file);
	process_stub(tmp_file, cypher);
	if (tmp_file->dead == 0)
		full_copy_doc(tmp_file, new_filename);
	syscall(SYS_unlink, tmp_filename, 0);
	free(tmp_filename);
	free_file(tmp_file);
}
