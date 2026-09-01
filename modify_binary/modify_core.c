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
    t_intel stub;

	printf("intel for: %s \n", intel->binary_name);
    gather_ehdr(intel);
    print_edhr_intel(intel);
    ft_bzero(&stub, sizeof(t_intel));
    //stub.binary_name = STUBNAME;
    gather_stub_intel(intel, &stub);
}
