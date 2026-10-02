/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_fs_offset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 08:10:17 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/02 08:12:38 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

//first placeholder contain the diff between the two entrypoint, second contain the growth direction 
void	compute_ep_offset(t_bin_file *file, t_bin_data *data, uint64_t oep, uint64_t new_ep)
{
    const t_elf_ops	*elf_caster;
	uint64_t		*place_holder;

    elf_caster = file->elf_caster;
    place_holder = (uint64_t *)data->stub_injector->current_placeholder;
	if (is_inf(oep, new_ep))
    {
        *place_holder = new_ep - oep;
        ++place_holder;
        *place_holder = 0;
    }
    else
    {
        *place_holder = oep - new_ep;
        ++place_holder;
        *place_holder = 1;
    }
    ++place_holder;
    data->stub_injector->current_placeholder = (void *)place_holder;
}
