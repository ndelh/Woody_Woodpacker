/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_basic_stub_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 08:10:35 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/09 08:12:11 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	compute_theorical_size_basic_stub_cpy(t_bin_data *data)
{
	uint64_t	needed_size;

	needed_size = data->stub_injector->av_core_offset + data->stub_injector->content_size + 1;
	data->copy_size = needed_size;
}

void	change_pt_note(t_bin_data *data, void *pt_note)
{
	(void)data;
	(void)pt_note;
}

void	fs_basic_stub_copy(t_bin_data *data)
{
	void		*pt_note_hdr;

	pt_note_hdr = find_first_phdr_of_type(data->core, data, PT_NOTE);
	if (!pt_note_hdr)
		return ;
	strip_shdr(data->core, data);
	compute_theorical_size_basic_stub_cpy(data);
	
}
