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
# include <stdio.h>
# include <elf.h>
# include <stdbool.h>

typedef struct	s_intel
{
	int		woody_fd;
	uint64_t	ogn_size;
	void		*ogn_begin;
	bool		is_64;

}	t_intel;

typedef struct s_lpad
{
	int	len;
	int offset;
}	t_lpad;


//utilitaries
	//pure utils
	int		ft_strlen(char *s);
	void	ft_bzero(void *s, size_t n);
	int	ft_memcmp(const void *s1, const void *s2, size_t n);
	//print_utils
	void	ft_putendl_fd(char *s, int fd);
	void	cr(int fd);
		//printf wrapper
			void	print_int(char *s, int i);


//init
	//map_init
	void	retrieve_ogn_map(char *s, t_intel *intel);
	//is_file_valid
	int	check_prerequisite(t_intel *intel);


#endif 
