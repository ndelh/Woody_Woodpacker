/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_modify_need.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 17:01:32 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/02 17:14:08 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../woody_woodpacker.h"

void	fetch_modify_need(t_intel *intel, t_intel *stub)
{
	(void)stub;
	printf("size found %lu\n", extension_space(intel));
}
