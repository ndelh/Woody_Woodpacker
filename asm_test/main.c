/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 05:11:57 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/08 07:34:29 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	ft_strlen(char *s)
{
	char *cursor;

	cursor = s;
	while (*cursor)
		++cursor;
	return (cursor - s);	
}

int	unprintable(char c)
{
	if (c < 32 || c > 126)
		return (1);
	return (0);
}

void	special_print(void *to_print, size_t len)
{
	unsigned char	*cursor;
	size_t		inc;

	cursor = (unsigned char *)to_print;
	inc = 0;
	while (inc < len)
	{
		++inc;
		if (!(*cursor))
			write(1,"NULL", 4);
		else if (!unprintable(*cursor))
			write(1, cursor, 1);
		else
			write(1, "unpr", 4);
		if (!(inc % 8))
		       write(1, "\n", 1);

		else
			write(1, " ", 1);
		++cursor;
	}
	write(1, "\n", 1);
}

void	*generate_key(void)
{
	int	fd;
	char	*s;
	
	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
	{
		perror("open failed");
		exit(1);
	}
	s = malloc(32);
	if (read(fd, s, 32) != 32)
	{
		free(s);
		perror("read failed");
	}
	return ((void *)s);
}
void	cr(void)
{
	write(1, "\n", 1);
}

int	main(int ac, char **argv)
{
	int len;
	char	*s;
	void	*key;

	if (ac != 2)
		return (1);
	s = argv[1];
	len = ft_strlen(s);
	key = generate_key();
	//special_print(key, 32);
	cr();
	ft_cypher(s, len, key);
	write(1, "after\n", 6);
	cr();
	special_print(s, len);
	cr();
	write(1, "undone\n", 7);
	ft_cypher(s, len, key);
	special_print(s, len);
	free(key);
}
