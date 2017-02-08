#include "filler.h"

static void ft_determ_border_top(t_filler *params, char type)
{
	int		i;
	char	*map;
	int		shift;
	int 	border;

	shift = 'a' - 'A';
	map = params->map;
	i = 0;
	while (map[i] != type && map[i] != type + shift && map[i] != '\0')
		i++;
	border = i / (params->map_width + 1);
	if (type == 'X')
		params->x_borders[0] = border;
	if (type == 'O')
		params->o_borders[0] = border;
}

static void ft_determ_border_bot(t_filler *params, char type)
{
	int		i;
	char	*map;
	int		shift;
	int 	border;

	shift = 'a' - 'A';
	map = params->map;
	i = 0;

	while (map[i] != '\0')
		i++;
	while (map[i] != type && map[i] != type + shift && i)
		i--;
	border = i / (params->map_width + 1);

	if (type == 'X')
		params->x_borders[1] = border;
	if (type == 'O')
		params->o_borders[1] = border;
}

static void ft_determ_border_left(t_filler *params, char type)
{
	int		i;
	char	*map;
	int 	border;
	int 	k;
	int 	j;

	map = params->map;
	i = 0;
	j = 0;
	k = 0;

	while (i < params->map_width && map[j] != type && map[j] != type + 'a' - 'A')
	{
		k = 0;
		j = i;
		while (k < params->map_hight && map[j] != type && map[j] != type + 'a' - 'A')
		{
			k++;
			if (k < params->map_hight)
				j = j + params->map_width + 1;

		}
		i++;

	}
	if (i == 0)
		i++;
	border = i - 1;


	if (type == 'X')
		params->x_borders[2] = border;
	if (type == 'O')
		params->o_borders[2] = border;
}

static void ft_determ_border_right(t_filler *params, char type)
{
	int		i;
	int 	border;
	int 	k;
	int 	j;
	int 	l;

	i = 0;
	k = 0;
	j = 0;
	l = 0;
	while (params->map[i] != '\0')
		i++;
	i = i - 2;
	l = params->map_width;
	j = i;
	while (l && params->map[j] != type && params->map[j] != type + 'a' - 'A')
	{
		k = 0;
		j = i;
		while (k < params->map_hight && params->map[j] != type && params->map[j] != type + 'a' - 'A')
		{
			j = j - params->map_width - 1;
			k++;
		}
		i--;
		l--;
	}
	border = l;
	if (type == 'X')
		params->x_borders[3] = border;
	if (type == 'O')
		params->o_borders[3] = border;
}

void	ft_determ_borders(t_filler *params)
{
	ft_determ_border_top(params, 'X');
	ft_determ_border_top(params, 'O');
	ft_determ_border_bot(params, 'X');
	ft_determ_border_left(params, 'X');
	ft_determ_border_right(params, 'X');
	ft_determ_border_bot(params, 'O');
	ft_determ_border_left(params, 'O');
	ft_determ_border_right(params, 'O');

}
