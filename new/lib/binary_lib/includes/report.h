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

# define PHDR_ONLY 1
# define SHDR_ONLY 2
# define BOTH_HDR 3

//main_func
void    report(char *filename, uint8_t flags);

//utils

int	open_report(char *s);

#endif
