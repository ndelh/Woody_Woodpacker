/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripped_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 05:37:00 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/09 05:37:59 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	stripped_copy(t_bin_data *data, char *s)
{

    strip_shdr(data->core, data);
    data->copy_size = retrieve_farthest_physical(data->core, data) + 1;
    simple_cpy(data, s);
}
