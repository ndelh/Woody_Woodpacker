/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody_woodpacker.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 15:09:17 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/20 15:56:36 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOODY_WOODPACKER_H
# define WOODY_WOODPACKER_H

# define ft_perror(x) ft_putendl_fd(x, 2)

# include <sys/mman.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_intel
{
	int		ogn_fd;
	int		woody_fd;
	uint32_t	ogn_size;
	void		*ogn_begin;
	void		*woody_begin;
}	t_intel;

//utilitaries
	//pure utils
	int		ft_strlen(char *s);
	void	ft_bzero(void *s, size_t n);
	//print_utils
	void	ft_putendl_fd(char *s, int fd);

//init
	void	init_core(char *s, t_intel *intel);


#endif 
