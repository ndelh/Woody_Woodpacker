/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barbarious_strip.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 14:50:21 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/10 15:11:04 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	barbarious_strip(char *s)
{
	char	*tmp_filename;
	t_bin_file	*tmp_file;
	uint64_t	initial_map_size;

	tmp_filename = gen_random_key(32);
	tmp_file = get_modifiable_copy(s, tmp_filename);
	if (!tmp_file)
		return ;
	initial_map_size = tmp_file->map_size;
	file_launcher(tmp_file, parse_all);
	file_launcher(tmp_file, absolute_strip);
	tmp_file->map_size = retrieve_farthest_needed_point(tmp_file);
	if (tmp_file->dead == 0)
		full_copy_doc(tmp_file, s);
	(void)s;
	syscall(SYS_unlink, tmp_filename, 0);
	tmp_file->map_size = initial_map_size;
	free_file(tmp_file);
	free(tmp_filename);
}
