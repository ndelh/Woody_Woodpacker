/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 07:38:11 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 07:38:38 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include "struct.h"

//iter on elf

void	iter_shdr(t_bin_file *file, void *aux_data, void(*func)(t_bin_file *file, void *, void *));
void	iter_phdr(t_bin_file *file, void *aux_data, void(*func)(t_bin_file *file, void *, void *));

#endif
