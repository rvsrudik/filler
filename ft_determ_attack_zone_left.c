#include "filler.h"

int	ft_determ_attack_zone_left(t_filler *p, char e, int *aim)
{
	int 		i;
	int			to_barrier;
	int 		attack_zone;
	int			j;
	int 		k;
	int 		z;


	to_barrier = 0;
	attack_zone = -1;
	i = 0;
	z = 0;
	while (i < p->map_width && p->map[j] != 'l')
	{
		j = i;
		k = 0;
		while (k < p->map_hight && p->map[j] != 'l')
		{
			k++;
			j = j + p->map_width + 1;
		}
		i++;
	}
	i = p->map_hight - (j / (p->map_width + 1));
	while (i >= 0)
	{
		z = 0;
		k = j;
		if (p->map[j + 1] == e || p->map[j + 1] == e + 'a' - 'A')
		{
			while (p->map[k] != '\n' && p->map[k] != p->player && p->map[k] != p->player + 'a' - 'A')
			{
				k--;
				z++;
			}
		}
		if (z > to_barrier)
		{
			attack_zone = j;
			to_barrier = z;
		}
		j = j + p->map_width + 1;
		i--;
	}
	*aim = attack_zone;
	if (attack_zone != -1)
		p->map[attack_zone] = '@';
	return (to_barrier);
}
