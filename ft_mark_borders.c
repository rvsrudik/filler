
#include "filler.h"

static void	ft_mark_borders_o_topbot(t_filler *p)
{
	int 		i;
	int 		koord;
	int 		tmp;

	i = 0;
	while (i < p->map_width)
	{
		koord = ((p->o_borders[0] - 1) * ((p->map_width) + 1) + i);
		tmp = koord + p->map_width + 1;
		if ((i >= p->o_borders[2] && i <= p->o_borders[3]
		&& p->map[koord] == '.') && (p->map[tmp] == 'O' || p->map[tmp] == 'o'))
			p->map[koord] = 't';
		i++;
	}
	i = 0;
	while (i < p->map_width)
	{
		koord = ((p->o_borders[1] + 1) * ((p->map_width) + 1) + i);
		tmp = koord - (p->map_width + 1);
		if ((i >= p->o_borders[2] && i <= p->o_borders[3]
		&& p->map[koord] == '.') && (p->map[tmp] == 'O' || p->map[tmp] == 'o') )
			p->map[koord] = 'b';
		i++;
	}

}


static void	ft_mark_borders_o_leftright(t_filler *p)
{
	int 		i;
	int 		koord;
	int 		tmp;

	i = 0;
	while (i <= (p->o_borders[1] - p->o_borders[0]))
	{
		koord = (((p->o_borders[0] + i) * ((p->map_width + 1)) + p->o_borders[2] - 1));
		tmp = koord + 1;
		if (p->map[koord] == '.' && (p->map[tmp] == 'O' || p->map[tmp] == 'o'))
			p->map[koord] = 'l';
		i++;
	}
	i = 0;
	while (i <= (p->o_borders[1] - p->o_borders[0]))
	{
		koord = (((p->o_borders[0] + i)* ((p->map_width + 1))) + p->o_borders[3] + 1);
		tmp = koord - 1;
		if (p->map[koord] == '.' && (p->map[tmp] == 'O' || p->map[tmp] == 'o'))
			p->map[koord] = 'r';
		i++;
	}
}

static void	ft_mark_borders_x_topbot(t_filler *p)
{
	int 		i;
	int 		koord;
	int 		tmp;

	i = 0;
	while (i < p->map_width)
	{
		koord = ((p->x_borders[0] - 1) * ((p->map_width) + 1) + i);
		tmp = koord + p->map_width + 1;
		if ((i >= p->x_borders[2] && i <= p->x_borders[3]
			 && p->map[koord] == '.') && (p->map[tmp] == 'X' || p->map[tmp] == 'x'))
			p->map[koord] = 't';
		i++;
	}
	i = 0;
	while (i < p->map_width)
	{
		koord = ((p->x_borders[1] + 1) * ((p->map_width) + 1) + i);
		tmp = koord - (p->map_width + 1);

		if ((i >= p->x_borders[2] && i <= p->x_borders[3] && p->map[koord] == '.')
		&& (p->map[tmp] == 'X' || p->map[tmp] == 'x') )
			p->map[koord] = 'b';
		i++;
	}
}

static void	ft_mark_borders_x_leftright(t_filler *p)
{
	int 		i;
	int 		koord;
	int 		tmp;

	i = 0;
	while (i <= (p->x_borders[1] - p->x_borders[0]))
	{
		koord = (((p->x_borders[0] + i)* ((p->map_width + 1)) + p->x_borders[2] - 1));
		tmp = koord + 1;
		if (p->map[koord] == '.' && (p->map[tmp] == 'X' || p->map[tmp] == 'x'))
			p->map[koord] = 'l';
		i++;
	}
	i = 0;
	while (i <= (p->x_borders[1] - p->x_borders[0]))
	{
		koord = (((p->x_borders[0] + i)* ((p->map_width + 1))) + p->x_borders[3] + 1);
		tmp = koord - 1;
		if (p->map[koord] == '.' && (p->map[tmp] == 'X' || p->map[tmp] == 'x'))
			p->map[koord] = 'r';
		i++;
	}
}

void	ft_mark_borders(t_filler *params)
{
	if (params->player == 'X')
	{
		ft_mark_borders_o_topbot(params);
		ft_mark_borders_o_leftright(params);
	}
	if (params->player == 'O')
	{
		ft_mark_borders_x_topbot(params);
		ft_mark_borders_x_leftright(params);
	}
}