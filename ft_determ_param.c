/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:59:53 by vrudenko          #+#    #+#             */
/*   Updated: 2017/02/05 18:59:56 by vrudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char *ft_determ_figuresize(t_filler *params, char *out)
{
	out = ft_strstr(out, "Piece");
	out += 6;
	params->figure_hight = ft_atoi(out);
	while (ft_isdigit(*out))
		out++;
	params->figure_width = ft_atoi(out);
	return (out);
}


static char *ft_determ_map(t_filler *params, char *out)
{
	char	*map;
	char 	*beginmap;
	int 	size;

	size = (params->map_hight * params->map_width) + params->map_hight;
	map = ft_strnew(size);
	beginmap = map;
	while  (*out != '.' && *out != 'o' && *out != 'O' && *out != 'x' && *out != 'X')
		out++;
	while (size)
	{
		if (*out == '.' || *out == '\n' || *out == 'o'
			|| *out == 'O' || *out == 'x' || *out == 'X')
		{
			*map = *out;
			map++;
			size--;
		}
			out++;
	}
	params->map = beginmap;
	return (out);
}

static char *ft_determ_figure(t_filler *params, char *out)
{
	char	*figure;
	char 	*begin;
	int 	size;

	size = params->figure_hight * params->figure_width + params->figure_hight;
	figure = ft_strnew(size);
	begin = figure;
	while  (*out != '.' && *out != '*')
		out++;
	//printf("%s\n", out);
	 while (size)
	{
		if (*out == '.' || *out == '\n' ||*out == '*')
		{
			*figure = *out;
			figure++;
		}
		out++;
		size--;
	}
	params->figure = begin;
	return (out);
}

static void	ft_determ_player(t_filler *params)
{
	char	player;
	int 	x;
	int 	o;
	char 	*map;

	map = params->map;
	x = 0;
	o = 0;
	player = '?';
	while (*map != '\0')
	{
		if (*map == 'x')
			player = 'O';
		if (*map == 'o')
			player = 'X';
		if (*map == 'X')
			x++;
		if (*map == 'O')
			o++;
		map++;
	}
	if (o == 1 && x == 1)
		player = 'O';
	params->player = player;
}

void ft_determ_param(t_filler *params, char *out)
{
	out = ft_strstr(out, "Plateau");
	out += 8;
	params->map_hight = ft_atoi(out);
	while (ft_isdigit(*out))
		out++;
	params->map_width = ft_atoi(out);
	ft_determ_map(params, out);
	out = ft_determ_figuresize(params, out);
	ft_determ_figure(params, out);
	ft_determ_player(params);
}