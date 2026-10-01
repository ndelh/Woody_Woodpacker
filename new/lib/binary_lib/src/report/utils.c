/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 12:10:57 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/01 12:12:56 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "report.h"
#include <fcntl.h>
int	open_report(char *s)
{
	int	fd;

	fd = open(s, O_RDWR | O_TRUNC);
	ft_putendl_fd("cannot create or open report file", 2);
	return (fd);
}
