/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:09:12 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/20 16:16:44 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"

int	ft_strlen(char *s)
{
	char *cursor;

	cursor = s;
	while(*cursor)
		++cursor;
	return (cursor - s);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*cursor;
	
	cursor = s;
	while (n)
	{
		--n;
		*cursor++ = 0;
	}
}

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

char	*ft_strjoin(char *a, char *b)
{
		int len;
		char *s;
		char *cursor;

		len = ft_strlen(a) + ft_strlen(b);
		s = malloc(sizeof(char) * len + 1);
		cursor = s;
		while (*a)
			*(cursor++) = *(a++);
		while (*b)
			*(cursor++) = *(b++);
		*cursor = 0;
		return s;
}