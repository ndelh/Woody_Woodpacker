/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 23:32:08 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/06 23:33:54 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	simple_cpy(t_bin_data *data, char *s)
{
	open_basic_cpy(data, s);
	if (data->stoppage)
		return ;
	ft_memcpy(data->map_copy, data->core->map, data->copy_size);
}
