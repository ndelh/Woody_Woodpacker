/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:17:39 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/04 16:17:59 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

int		ft_memcmp(const void *v1, const void *v2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	
	s1 = (unsigned char *)v1;
	s2 = (unsigned char *)v2;
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		++s2;
		++s1;
	}
	return (0);
}
