/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positive_pnumber.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 15:35:08 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/06 15:52:18 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void    positive_pnumber(unsigned int i, int fd)
{
    if (i > 9)
        positive_pnumber(i / 10, fd);
    ft_putchar_fd((i % 10) + '0', fd);
}