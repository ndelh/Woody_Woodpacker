/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_first_phdr_of_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 04:52:27 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/09 04:52:39 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

typedef struct t_f_ptype
{
    void    *phdr;
    uint64_t    type;
    bool        found;
} t_f_ptype;

void    iter_find_first_phdr_of_type(t_bin_file *file, t_bin_data *data, void *aux_data, void *cursor)
{
    t_f_ptype   *aux;

    (void)data;
    aux = (t_f_ptype *)aux_data;
    if (aux->found)
        return ;
    if (file->elf_caster->get_ptype(cursor) == aux->type)
    {
        aux->phdr = cursor;
        aux->found = true;
        printf("found ptype\n");
    }
}
void    *find_first_phdr_of_type(t_bin_file *file, t_bin_data *data, uint64_t type)
{
    t_f_ptype   aux_data;

    aux_data.phdr = NULL;
    aux_data.type = type;
    aux_data.found = 0;
    iterate_phdr(file, data, &aux_data, iter_find_first_phdr_of_type);
    if (!aux_data.phdr)
        register_error(data, "cannot found the requested ptype phdr", file);
    return (aux_data.phdr);
}