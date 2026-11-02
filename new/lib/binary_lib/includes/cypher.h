/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cypher.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 17:26:52 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/30 17:27:31 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYPHER_H
# define CYPHER_H

# include "struct.h"

void	cypher_pt_load(t_bin_file *target, t_bin_file *stub);
void    load_s_xor_intel_64(void *helper, uint64_t content_load_addr, uint64_t content_size, uint64_t current_perm);
void    load_s_xor_intel_32(void *helper, uint64_t content_load_addr, uint64_t content_size, uint64_t current_perm);

//utilities
void	*go_to_key_32(void *cursor);

#endif
