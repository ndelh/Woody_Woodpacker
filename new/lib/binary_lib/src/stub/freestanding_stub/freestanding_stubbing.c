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
		file = get_writable_unshared_file("stub64.o");
	else
		return  NULL;
	file_launcher(file, parse_all);
	file_launcher(file, print_ehdr);
	return (file);
}

void	process_stub(t_bin_file *tmp_file)
{
	t_bin_file	*stub;

	stub = get_stub(get_byte_type(tmp_file->map));
	file_launcher(stub, gather_fs_stub_data);
	tmp_file->dead = stub->dead;
	freestanding_caving_stub(tmp_file, stub);
	if (stub)
		free_file(stub);
}
void	free_standing_stubbing(char *og_filename, char *new_filename, bool cypher)
{
	char	*tmp_filename;
	t_bin_file *tmp_file;

	(void)cypher;
	if ((tmp_filename = gen_random_key(32)) == NULL)
		return ;
	tmp_file = get_modifiable_copy(og_filename, tmp_filename);
	file_launcher(tmp_file, parse_all);
	file_launcher(tmp_file, process_stub);
	if (tmp_file->dead == 0)
		full_copy_doc(tmp_file, new_filename);
	syscall(SYS_unlink, tmp_filename, 0);
	free_file(tmp_file);
	free(tmp_filename);
}
