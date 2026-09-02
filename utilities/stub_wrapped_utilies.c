/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stub_wrapped_utilies.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:59:33 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/01 16:05:39 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"

bool	is_placeholder(uint64_t current)
{
	return (current == PLACEHOLDER);
}

bool	count_placeholder(unsigned char *cursor, uint64_t len, uint64_t compare)
{
		uint64_t remaining;
		
		remaining = PLACEHOLDERNB - 1;
		if (len < 8 && remaining)
			return (false);
		len -= 8;
		cursor += 8;
		while (len >= 8)
		{
			ft_memcpy(&compare, cursor, 8);
			if (is_placeholder(compare))
			{
				remaining -= 1;
				cursor += 8;	
			}
			else
				break ;
		}
		printf("remaining %lu\n", remaining);
		return (remaining == 0);
}

bool	retrieve_placeholder(t_intel *intel)
{
	t_stub_loader	*stub;
	unsigned char	*cursor;
	uint64_t	compare;
	uint64_t	len;

	stub = &intel->stub_loader;
	len = stub->content_size;
	printf("len value: %lx\n", stub->content_size);
	cursor = (unsigned char *)stub->content_begin;
	while (len-- >= 8)
	{
		ft_memcpy(&compare, cursor, 8);
		if (is_placeholder(compare))
		{
			stub->placeholder_begin = cursor;
			if (count_placeholder(cursor, len, compare))
				printf("all found\n");
			return (0);
		}
		++cursor;
	}
	return (0);
}