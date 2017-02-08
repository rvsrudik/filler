
#include "filler.h"


int	ft_determ_attack_zone_bot(t_filler *p, char e, int *aim)
{
	int		i;
	int 	j;
	int 	k;
	int		to_barrier;
	int 	attack_zone;

	to_barrier = 0;
	attack_zone = -1;
	i = 0;
	while (p->map[i] != '\0')
		i++;
	while (p->map[i] != 'b')
		i--;

	while (p->map[i] != '\n')
	{
		k = 0;
		j = i;
		if (p->map[j - p->map_width - 1] == e || p->map[j - p->map_width - 1] == e + 'a' - 'A')
		{
			while (j <= ((p->map_width + 1) * p->map_hight) && (p->map[j] != p->player && p->map[j] != p->player + 'a' - 'A'))
			{
				k++;
				j = j + p->map_width + 1;
			}
		}
		if (k > to_barrier)
		{
			attack_zone = i;
			to_barrier = k;
		}
		i--;
	}
	*aim = attack_zone;
	if (attack_zone != -1)
		p->map[attack_zone] = '@';

	return (to_barrier);
}
