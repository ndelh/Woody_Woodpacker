/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shdr_by_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 03:19:03 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/07 03:22:30 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "binary_lib.h"

typedef struct  s_find_name
{
    char    *name;
    void    *shdr_begin;
    bool     found;
}   t_find_name;

void	check_name(t_bin_file *file, t_bin_data *data, void *aux_data, void *cursor)
{
    t_find_name *name;
    
    (void)data;
    name = (t_find_name *)aux_data;
    if (name->found)
        return ;
    if (!ft_strcmp(get_name(cursor, file), name->name))
    {
        name->found = 1;
        name->shdr_begin = cursor;
    }
}

void    *find_shdr_by_name(t_bin_file *file, t_bin_data *data, char *name)
{
    t_find_name to_find;
    void        *to_ret;

    ft_bzero(&to_find, sizeof(t_find_name));
    to_find.name = name;
    iterate_shdr(file, data, &to_find, check_name);
    to_ret = to_find.shdr_begin;
    return (to_ret);
}
