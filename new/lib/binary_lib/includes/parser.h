/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:04:09 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/08 18:05:18 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdint.h>
# include "struct.h"

void		parse_all(t_bin_file *file);
void		first_parse(t_bin_file *file);
void	    parse_ehdr_content(t_bin_file *file);


//first header utils
bool	    is_not_elf(const void *map);
uint64_t	get_byte_type(const void *map);
bool	    is_b_endian(const void *map);
bool        is_version_unvalid(const void *map);
void	    load_ehdr_content(t_bin_file *file);

//boundary_check
bool	    is_struct_oob(t_bin_file *intel, uint64_t offset, uint64_t struct_nb, uint64_t struct_size);
bool	    is_strtab_unvalid(unsigned char *s, size_t len);
void	    shstrndx_validity(t_bin_file *file);

//iterable
void	shdr_range_check(t_bin_file *file, void *aux_data, void *cursor);
void	phdr_range_check(t_bin_file *file, void *aux_data, void *cursor);

#endif
