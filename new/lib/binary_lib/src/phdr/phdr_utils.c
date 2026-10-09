/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phdr_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 14:37:31 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 14:37:46 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phdr.h"

uint64_t	find_bss_size(const t_elf_ops *elf_caster, void *cursor)
{
	return (elf_caster->get_pmemsz(cursor) - elf_caster->get_pfilesz(cursor));
}
