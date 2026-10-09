/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_random_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 08:49:49 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 09:21:49 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"


int	fill_key(char *key, uint64_t size)
{
	int	to_ret;
	int	fd;
	
	to_ret = 1;
	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
	{
		register_error("failed to open /dev/urandom", NULL);
		to_ret = -1;
	}
	else
	{
		if (read(fd, key, size) != (ssize_t)size)
		{
			register_error("read failed while generating random key", NULL);
			to_ret = -1;
		}
		close(fd);
	}
	return (to_ret);
}

char	*gen_random_key(uint64_t size)
{
	char	*key;

	key = malloc(sizeof(char) * (size + 1));
	if (!key)
		register_error("failed to allocate random key", NULL);
	else
	{
		ft_bzero(key, size + 1);
		if (fill_key(key, size) == - 1)
		{
			free(key);
			key = NULL;
		}
	}
	return (key);
}
