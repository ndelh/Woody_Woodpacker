/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 12:26:52 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/01 12:32:41 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	warn(char *s)
{
	ft_putstr_fd("WARNING: ", 1);
	ft_putendl_fd(s , 1);
}

void	file_warning(char *s, t_bin_file *file)
{
	ft_putstr_fd("WARNING in following file:", 1);
	ft_putstr_fd(file->path, 1);
	ft_putendl_fd(s , 1);
}
