/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phdr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 14:38:59 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 14:41:03 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHDR_H
# define PHDR_H

#include "struct.h"
#include "stdint.h"
//utilies

uint64_t	find_bss_size(const t_elf_ops *elf_caster, void *cursor);

//strip related
uint64_t   retrieve_farthest_needed_point(t_bin_file *file);


#endif
