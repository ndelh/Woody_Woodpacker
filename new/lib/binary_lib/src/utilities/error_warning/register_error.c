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

void	register_error(t_bin_data *data, char *msg, t_bin_file *file)
{
	ft_putstr_fd("Error number: ", STDERR_FILENO);
	positive_pnumber(data->stoppage++, STDERR_FILENO);
	cr(STDERR_FILENO);
	if (file)
	{
		ft_putstr_fd("for file: ", STDERR_FILENO);
		ft_putendl_fd(file->path, STDERR_FILENO);
	}
	if (msg)
		ft_putendl_fd(msg, STDERR_FILENO);
	cr(STDERR_FILENO);
}
