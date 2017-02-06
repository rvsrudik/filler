/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftller.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 19:00:12 by vrudenko          #+#    #+#             */
/*   Updated: 2017/02/05 19:00:14 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define BUFF_SIZE 20

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
#include <stdio.h>
#include "libft.h"

typedef struct	s_filler
{
	char	*map;
	char	*figure;
	char 	player;
	int		map_width;
	int		map_hight;
	int		figure_width;
	int		figure_hight;

}			t_filler;

void ft_determ_param(t_filler *params, char *out);


#endif
