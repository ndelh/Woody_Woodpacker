/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stub.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:36:49 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 10:39:42 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUB_H
#define STUB_H

void	free_standing_stubbing(char *og_filename, char *new_filename, bool cypher);

//fetching data
void    gather_fs_stub_data(t_bin_file *file);
void	fs_find_canaries_64(t_bin_file *stub, void *cursor, uint64_t size);
void	fs_find_canaries_32(t_bin_file *stub, void *cursor, uint64_t size);
void	compute_ep_offset(t_bin_file *file, t_bin_file *stub, uint64_t oep, uint64_t new_ep);

//caving
void    *find_cave(t_bin_file *target, uint64_t size);
bool	freestanding_caving_stub(t_bin_file *target, t_bin_file *stub, bool cypher);
//pt_noting
#endif
