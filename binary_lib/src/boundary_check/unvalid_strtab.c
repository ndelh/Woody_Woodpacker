/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unvalid_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:47:44 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/05 13:48:04 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

bool	is_strtab_unvalid(unsigned char *s, size_t len)
{
	if (*s || !len)
		return (1);
	s += len;
	if (*s)
		return (1);
	return (0);
}
