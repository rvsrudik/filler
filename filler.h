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

#define PRINT_PLAYER 1
#define PRINT_MAP 0
#define PRINT_FIGURE 0
#define	PRINT_BORDERS 1

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
#include <stdio.h>
#include "libft.h"

typedef struct	s_filler
{
	int		x_borders[4];
	int		o_borders[4];
	int		map_width;
	int		map_hight;
	int		figure_width;
	int		figure_hight;

	char	*map;
	char	*figure;
	char 	player;

}			t_filler;

/*
**======================GENERAL=====================**
*/
void ft_determ_param(t_filler *params, char *out);
void ft_determ_borders(t_filler *params);
/*
**================================================**
*/

/*
**======================DEBUG=====================**
*/
	void ft_print_params(t_filler *params);
/*
**================================================**
*/


#endif
