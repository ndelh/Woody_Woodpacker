/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_entry_phdr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 13:15:26 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/12 13:17:10 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

typedef struct s_entry_phdr
{
	void		*phdr;
	uint64_t	entrypoint;
	bool		found;
}	t_entry_phdr;

void	ite_retrieve_entry_phdr(t_bin_file *file, t_bin_data *data, void *helper, void *cursor)
{
	if (file->elf_caster->get_ptype(cursor) == PT_LOAD)
	{
		if (((t_entry_phdr *)helper)->entrypoint == file->elf_caster->get_pvaddr(cursor))
		{
			printf("found\n");
			((t_entry_phdr *)helper)->phdr = cursor;
			((t_entry_phdr *)helper)->found = true;
		}
	}
}

void	*retrieve_entry_phdr(t_bin_file *file, t_bin_data *data)
{
	t_entry_phdr	helper;

	ft_bzero(&helper, sizeof(t_entry_phdr));
	helper.entrypoint = file->intel->e_entry;
	iterate_phdr(file, data, &helper, ite_retrieve_entry_phdr);
	if (helper.phdr == NULL)
		register_error(data, "entrypointphdr cannot be found", file);
	return (helper.phdr);
}
