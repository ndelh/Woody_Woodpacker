/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:08:02 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/20 16:51:17 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"

void	cr(int fd)
{
	write(fd, "\n", 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	cr(fd);
}

void	print_int(char *s, int i)
{
	ft_putendl_fd(s, 1);
	printf(": %d\n", i);
}
