/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 11:44:38 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/27 11:45:24 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"
#include "elf_64.h"

const	t_elf_ops   ops_64 = {
    .get_entry = get_entry_64,
    .get_phdr_offset = get_phdr_offset_64,
    .get_phdr_nb = get_phdr_nb_64,
    .get_phdr_size = get_phdr_size_64,
    .get_shdr_offset = get_shdr_offset_64,
    .get_shdr_nb = get_shdr_nb_64,
    .get_shdr_size = get_shdr_size_64,
    .get_shstrndx = get_shstrndx_64
};
