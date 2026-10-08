/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opener.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:57:54 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/08 15:58:14 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENER_H
# define OPENER_H
# include "struct.h"

//opener

t_bin_file	*get_read_only_file(char *s);
t_bin_file  *get_modifiable_copy(char *s, char *copy_name);

//utils
void        compute_map_size(t_bin_file *file);
int         open_wrapper(char *s, int flags, int perm);
void        open_mmap(t_bin_file *file, int prot, int flag);
void        extend_file(int fd, uint64_t added_size, uint64_t old_size, t_bin_file *file);


#endif
