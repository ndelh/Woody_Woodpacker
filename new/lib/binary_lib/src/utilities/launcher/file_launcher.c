/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_launcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:09:24 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/08 18:16:20 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"

void	file_launcher(t_bin_file *file, void(*func)(t_bin_file *))
{
	if (file->dead)
		return ;
	func(file);
}
