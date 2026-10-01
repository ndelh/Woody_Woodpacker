/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 11:15:14 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/01 12:08:43 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_lib.h"
#include "report.h"

void	report(t_elf_ops *elf_caster, t_bin_file *file, char *report_name)
{
    int fd;
    fd = open_report(report_name);
    if (fd == -1)
        return ;
}
