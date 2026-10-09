/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_first_of_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 03:19:03 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 12:15:32 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "binary_lib.h"

typedef struct  s_find_name
{
    char    *name;
    void    *shdr;
    bool     found;
}   t_find_name;

void	check_name(t_bin_file *file, void *aux_data, void *cursor)
{
    t_find_name *name;
    
    name = (t_find_name *)aux_data;
    if (name->found)
        return ;
    if (!ft_strcmp(get_name(cursor, file), name->name))
    {
        name->found = 1;
        name->shdr = cursor;
    }
}

void    *find_first_shdr_of_name(t_bin_file *file, char *name)
{
    t_find_name to_find;

    ft_bzero(&to_find, sizeof(t_find_name));
    to_find.name = name;
    iter_shdr(file, &to_find, check_name);
    if (!(to_find.shdr))
        register_error("cannot find the asked shdr name", file);
    return (to_find.shdr);
}
