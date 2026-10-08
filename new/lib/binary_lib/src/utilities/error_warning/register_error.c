/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 15:24:57 by ndelhota          #+#    #+#             */
/*   Updated: 2026/09/06 15:33:37 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	register_error(char *msg, t_bin_file *file)
{
	static int	error_nb;
	ft_putstr_fd("Error number: ", STDERR_FILENO);
	positive_pnumber(++error_nb, STDERR_FILENO);
	cr(STDERR_FILENO);
	if (file)
	{
		ft_putstr_fd("for file: ", STDERR_FILENO);
		ft_putendl_fd(file->path, STDERR_FILENO);
		file->dead = true;
	}
	if (msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	cr(STDERR_FILENO);
}
