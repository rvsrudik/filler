
#include "filler.h"

static void ft_print_params(t_filler *params)
{
	printf("===========MAP============\n");
	printf("[%d] x [%d]\n", params->map_width, params->map_hight);
	printf("%s", params->map);
	printf("===========================\n");

	printf("===========FIGURE==========\n");
	printf("[%d] x [%d]\n", params->figure_width, params->figure_hight);
	printf("%s", params->figure);
	printf("===========================\n");

	printf("===========BORDERS=========\n");
//	printf("---%d---   ---%d---\n", params->o_borders[0], params->x_borders[0]);
	printf("===========================\n");
}

static char *ft_read_out()
{
	int		ret;
	char	*buff;
	char	*tmp;
	char	*out;

	tmp = NULL;
	buff = NULL;
	buff = ft_strnew(BUFF_SIZE);
	tmp  = ft_strnew(0);
	ret = 0;
	while ((ret = read(0, buff, 20)))
	{
		buff[ret] = '\0';
		out = ft_strjoin(tmp, buff);
		if (tmp)
			ft_strdel(&tmp);
		tmp = out;
		if (buff)
			ft_strdel(&buff);
		buff = ft_strnew(BUFF_SIZE);
	}
	return (out);
}

static void ft_determ_borders(t_filler *params, char type)
{
	int		i;
	char	*map;
	int		shift;
	int 	borders[4];
	int 	k;
	int 	j;


	shift = 'a' - 'A';
	map = params->map;
	i = 0;
	while (map[i] != type && map[i] != type + shift && map[i] != '\0')
		i++;
	borders[0] = i / params->map_width;
	while (map[i] != '\0')
		i++;
	while (map[i] != type && map[i] != type + shift && i)
		i--;
	borders[1] = i / params->map_width;
	i = 0;
	while (i < params->map_width && map[j] != type && map[j] != type + shift)
	{
		k = 0;
		j = i;
		while (k < params->map_hight && map[j] != type && map[j] != type + shift)
		{
			j = j + params->map_width + 1;
			k++;
		}
		i++;
	}
	borders[2] = i - 1;


	j = 0;
	while (map[i] != '\0')
		i++;
	i = i - 2;
	int l = 0;

	l = params->map_width;
	while (l && map[j] != type && map[j] != type + shift)
	{
		k = 0;
		j = i;
		while (k < params->map_hight && map[j] != type && map[j] != type + shift)
		{
			j = j - params->map_width - 1;
			k++;

		}
		i--;
		l--;
	}
	borders[3] = l;

	int *tmp;


	tmp = malloc(sizeof(int) * 4);


//	if (params->player == 'X')
//	{
//		borders->x_borders[0] = borders[0];
//		borders->x_borders[1] = borders[1];
//		borders->x_borders[2] = borders[2];
//		borders->x_borders[3] = borders[3];
//	}
//
//	if (params->player == 'O')
//	{
//		tmp[0] = borders[0];
//		tmp[1] = borders[1];
//		tmp[2] = borders[2];
//		tmp[3] = borders[3];
//	}




	//if (params->player == 'X')
	//{
	//	params->o_borders = borders;
	//}
	//printf("---%d---   ---%d---\n", params->o_borders[0], params->x_borders[0]);
	//printf("---%d---   ---%d---\n", params->o_borders[3], params->x_borders[3]);

}

int main(void)
{
	char		*out;
	t_filler	*params;
	t_border	*border;

	border = (t_border*)malloc(sizeof(border));
	params = (t_filler*)malloc(sizeof(params));
	out = ft_read_out();
	ft_determ_param(params, out);

//	ft_determ_borders(params, 'X', border->x_borders);
	ft_determ_borders(params, 'O');

//	printf("%d\n", border->o_borders[0]);
//	printf("%d\n", border->o_borders[1]);
//	printf("%d\n", border->o_borders[2]);
//	printf("%d\n", border->o_borders[3]);

//	printf("%d\n", border->o_borders[0]);
//	printf("%d\n", border->o_borders[1]);
//	printf("%d\n", border->o_borders[2]);
//	printf("%d\n", border->o_borders[3]);


	//printf("%d, %d, %d, %d\n", params->x_borders[0], params->x_borders[1], params->x_borders[2], params->x_borders[3]);
	//printf("%d, %d, %d, %d\n", params->o_borders[0], params->o_borders[1], params->o_borders[2], params->o_borders[3]);
	//printf("---%d---   ---%d---\n", params->o_borders[0], params->x_borders[0]);
	//printf("---%d---   ---%d---\n", params->o_borders[3], params->x_borders[3]);

//	ft_print_params(params);
//	printf("m hight - |%d|\n", params->map_hight);
//	printf("m width - |%d|\n\n", params->map_width);
//	printf("%s\n", params->map);
// printf("f hight - |%d|\n", params->figure_hight);
//	printf("f width - |%d|\n\n", params->figure_width);
//	printf("%s", params->figure);
//	printf("player |%c|\n", params->player);

	return (0);
}