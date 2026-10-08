/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_writable_copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:41:38 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/08 17:41:47 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void    process_copy_opening(t_bin_file *og, t_bin_file *copy)
{
    copy->fd = open_wrapper(copy->path, O_RDWR | O_TRUNC | O_CREAT, 0777);
    if (copy->fd == -1)
    {
        register_error("failed to open/create the copy file", copy);
        return ;
    }
    extend_file(copy->fd, og->map_size, 0, copy);
    open_mmap(copy, PROT_READ | PROT_WRITE, MAP_SHARED);
}

void    copy_og(t_bin_file *og, t_bin_file *copy)
{
    if (copy->dead)
        return ;
    ft_memcpy(copy->map, og->map, copy->map_size);
}

t_bin_file  *get_modifiable_copy(char *s, char *copy_name)
{
    t_bin_file  *og;
    t_bin_file  *copy;

    og = get_read_only_file(s);
    if (!og || og->dead)
    {
        register_error("unable to open the copy target file", NULL);
        return NULL;
    }
    copy = malloc_wrapper(1, sizeof(t_bin_file), "trying to allocate the copy file struct");
    if (!copy)
    {
        free_file(og);
        return NULL;
    }
    copy->path = copy_name;
    process_copy_opening(og, copy);
    copy_og(og, copy);
    free_file(og);
    return (copy);
}