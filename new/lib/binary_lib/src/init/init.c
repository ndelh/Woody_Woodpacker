/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 11:58:25 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/06 11:59:40 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void    *alloc_wrapper(size_t size, t_bin_data *data, t_bin_file *file)
{
    void    *allocated;

    allocated = malloc(size);
    if (!allocated)
        register_error(data, "malloc failed", file);
    else
        ft_bzero(allocated, size);
    return (allocated);
}


t_file_intel    *alloc_file_intel(t_bin_data *data, t_bin_file *file)
{
    t_file_intel    *allocated;

    allocated = alloc_wrapper(sizeof(t_file_intel), data, file);
    return (allocated);
}

t_bin_file  *alloc_file(char *s, t_bin_data *data)
{
    t_bin_file  *allocated;
    
    allocated = malloc(sizeof(t_bin_file));
    if (!allocated)
    {
        data->stoppage = 1;
        return NULL;
    }
    ft_bzero(allocated, sizeof(t_bin_file));
    allocated->path = s;
    allocated->intel = alloc_file_intel(data, NULL);
    allocated->fd = -1;
    allocated->map = MAP_FAILED;
    return (allocated);
}

void        load_file_struct(char *core_file, char *stub, t_bin_data *data)
{
    data->core = alloc_file(core_file, data);
    if (!data->stoppage && stub)
        data->stub = alloc_file(stub, data);
}

t_bin_data  *init(char *core_file, char *stub)
{
    t_bin_data  *data;

    data = malloc(sizeof(t_bin_data));
    if (!data)
        return (NULL);
    ft_bzero(data, sizeof(t_bin_data));
    data->copy_fd = -1;
    data->map_copy = MAP_FAILED;
    load_file_struct(core_file, stub, data);
    data->stub_injector = alloc_wrapper(sizeof(t_stub_injector), data, NULL);
    return (data);
}
