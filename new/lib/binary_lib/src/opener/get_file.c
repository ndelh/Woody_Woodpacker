/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_simple_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:05:16 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/08 17:41:12 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void    process_read_only_opening(t_bin_file *file)
{

    file->fd = open_wrapper(file->path, O_RDONLY, 0);
    if (file->fd == -1)
    register_error("failed to open the asked file", file);
    compute_map_size(file);
    open_mmap_file(file, PROT_READ, MAP_PRIVATE);
}

t_bin_file	*get_read_only_file(char *s)
{
    t_bin_file  *file;

    if ((file = malloc_wrapper(1, sizeof(t_bin_file), "trying to allocate file struct")) == NULL)
        return NULL;
    file->path = s;
    process_read_only_opening(file);
    return (file);
}

void    process_writable_unshared_opening(t_bin_file *file)
{
    file->fd = open_wrapper(file->path, O_RDWR, 0);
    if (file->fd == -1)
    register_error("failed to open the asked file", file);
    compute_map_size(file);
    open_mmap_file(file, PROT_READ | PROT_WRITE, MAP_PRIVATE);
}

t_bin_file	*get_writable_unshared_file(char *s)
{
    t_bin_file  *file;

    if ((file = malloc_wrapper(1, sizeof(t_bin_file), "trying to allocate file struct")) == NULL)
        return NULL;
    file->path = s;
    process_writable_unshared_opening(file);
    return (file);
}

