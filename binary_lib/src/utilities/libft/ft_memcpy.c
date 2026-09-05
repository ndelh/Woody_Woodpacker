/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:18:17 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/04 16:18:34 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s1;
	unsigned char		*d2;

	s1 = (unsigned char *)src;
	d2 = (unsigned char *)dest;

	while (n--)
	{
		*d2 = *s1;
		++s1;
		++d2;
	}
}