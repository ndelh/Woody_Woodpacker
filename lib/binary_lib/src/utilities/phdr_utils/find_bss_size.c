/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bss_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:55:13 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/13 17:55:48 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

uint64_t	find_bss_size(const t_elf_ops *elf_caster, void *cursor)
{
	return (elf_caster->get_pmemsz(cursor) - elf_caster->get_pfilesz(cursor));
}
