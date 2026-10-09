/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shdr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 12:16:03 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 12:17:00 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHDR_H
# define SHDR_H

//name related

char	*get_name(void *cursor, t_bin_file *file);
void    *find_first_shdr_of_name(t_bin_file *file, char *name);

#endif
