
#include "filler.h"

static void ft_del_borders(t_filler *params)
{
	int 	i;

	i = 0;

	while (params->map[i] != '\0')
	{
		if (params->map[i] == 't' || params->map[i] == 'b' || params->map[i] == 'r' || params->map[i] == 'l')
			params->map[i] = '.';
		i++;
	}
}

static void ft_norm_one(t_filler *params, int barier[])
{
	(barier[1] > -1) ? params->map[barier[1]] = '.' : 0;
	barier[0] = 0;
}

void	ft_determ_attack_zone(t_filler *params)
{
	char 		enemy;
	int 		top_barier[2];
	int 		bot_barier[2];
	int 		left_barier[2];
	int			right_barier[2];

	if (params->player == 'X')
		enemy = 'O';
	else if (params->player == 'O')
		enemy = 'X';
	top_barier[0] = ft_determ_attack_zone_top(params, enemy, &top_barier[1]);
	bot_barier[0] = ft_determ_attack_zone_bot(params, enemy, &bot_barier[1]);
	left_barier[0] = ft_determ_attack_zone_left(params, enemy, &left_barier[1]);
    right_barier[0] = ft_determ_attack_zone_right(params, enemy, &right_barier[1]);
	ft_del_borders(params);

/*
 	printf("%d   %d\n", top_barier[0], top_barier[1]);
	printf("%d   %d\n", bot_barier[0], bot_barier[1]);
	printf("%d   %d\n", left_barier[0], left_barier[1]);
  	printf("%d   %d\n", right_barier[0], right_barier[1]);
  	*/

	if (top_barier[0] <= bot_barier[0] || top_barier[0] <= right_barier[0] || top_barier[0] <= left_barier[0])
		ft_norm_one(params, top_barier);
	if (bot_barier[0] <= top_barier[0] || bot_barier[0] <= left_barier[0] || bot_barier[0] <= right_barier[0])
		ft_norm_one(params, bot_barier);
	if (left_barier[0] <= top_barier[0] || left_barier[0] <= bot_barier[0] || left_barier[0] <= right_barier[0])
		ft_norm_one(params, left_barier);
	if (right_barier[0] <= top_barier[0] || right_barier[0] <= bot_barier[0] || right_barier[0] <= left_barier[0])
		ft_norm_one(params, right_barier);
}