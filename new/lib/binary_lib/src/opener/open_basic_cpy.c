/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_basic_cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 22:56:05 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/06 23:14:29 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"


void	open_basic_cpy(t_bin_data *data, char *s)
{
	if (data->stoppage)
		return ;
	data->copy_size = data->core->map_size;
	open_extend(data, s);
}
