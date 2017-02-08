#include "filler.h"

static void	ft_norm_one(int *attack_zone, int *i, int *to_barrier, int *k)
{
	*attack_zone = *i;
	*to_barrier = *k;
}

static void ft_norm_two(int *to_barrier, int *attack_zone, int *i, t_filler *p)
{
	int j;

	j = 0;
	while (p->map[j] != 't' && p->map[j] != '\0')
		j++;
	*to_barrier = 0;
	*attack_zone = -1;
	*i = j;
}

int			ft_determ_attack_zone_top(t_filler *p, char e, int *aim)
{
	int		i;
	int 	j;
	int 	k;
	int		to_barrier;
	int 	attack_zone;

	ft_norm_two(&to_barrier, &attack_zone, &i, p);
	while (p->map[i] != '\n')
	{
		k = 0;
		j = i;
		if (p->map[j + p->map_width + 1] == e || p->map[j + p->map_width + 1] == e + 'a' - 'A')
		{
			while (j >= 0 && p->map[j] != p->player && p->map[j] != p->player + 'a' - 'A')
			{
				k++;
				j = j - p->map_width - 1;
			}
		}
		(k > to_barrier) ? (ft_norm_one(&attack_zone, &i, &to_barrier, &k)) : 0;

		i++;
	}
	*aim = attack_zone;
	(attack_zone != -1) ? p->map[attack_zone] = '@' : 0;
	return (to_barrier);
}