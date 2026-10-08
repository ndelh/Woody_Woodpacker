/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_wrapper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:07:24 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/08 15:15:43 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	*malloc_wrapper(uint64_t nb, uint64_t size, char *msg)
{
	unsigned char	*to_ret;
	
	to_ret = malloc(nb * size);
	if (!to_ret)
		register_error(msg, NULL);
	else
		ft_bzero(to_ret, size * nb);
	return (to_ret);
}
