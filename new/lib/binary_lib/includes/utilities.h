/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 09:23:27 by ndelhota          #+#    #+#             */
/*   Updated: 2026/10/09 09:24:57 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

char	*gen_random_key(uint64_t size);
void	full_copy_doc(t_bin_file *file, char *target_doc);

//error_warning
void	register_error(char *msg, t_bin_file *file);
void	warn(char *s);
void	file_warning(char *s, t_bin_file *file);

#endif 
