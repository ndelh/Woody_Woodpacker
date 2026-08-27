/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 18:27:45 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/26 18:28:00 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"

void	modify_core(t_intel *intel)
{
    t_lpad  longest_padding;

    ft_bzero(&longest_padding, sizeof(t_lpad));
	printf("modify sucessfully entered for: %s \n", intel->binary_name);
    retrieve_lpad(&longest_padding, intel);
    print_int("longest padding space size", longest_padding.len);
    print_int("longest padding offset", longest_padding.offset);
}
