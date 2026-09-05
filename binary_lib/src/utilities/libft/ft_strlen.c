/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:10:55 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/04 16:15:53 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "binary_lib.h"

int	ft_strlen(char *s)
{
	char	*cursor;
	
	if (!s)
		return (0);
	cursor = s;
	while (*cursor)
		++cursor;
	return (cursor - s);
}
