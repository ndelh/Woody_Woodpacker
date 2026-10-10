/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 12:09:09 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/01 12:10:44 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPORT_H
# define REPORT_H

//main_func
void    report(t_elf_ops *elf_ops, t_bin_file *file, char *s);

//utils

int	open_report(char *s);

#endif
